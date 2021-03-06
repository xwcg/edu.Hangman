#include "graphics.h"

// Initializes console handles and defaults
void G_Init()
{
	// Get the handle to our console output
	_CONSOLE_HANDLE = GetStdHandle (STD_OUTPUT_HANDLE);

	// Read current ( = default ) values
	GetConsoleScreenBufferInfo (_CONSOLE_HANDLE, &_CONSOLE_INFO);

	// And save the attributes
	_CONSOLE_DEFAULTS = _CONSOLE_INFO.wAttributes;

	// Initialize screen buffer
	int x = 0;
	int y = 0;

	for(x = 0; x < G_DEFAULT_WIDTH; x++)
	{
		for(y = 0; y < G_DEFAULT_HEIGHT; y++)
		{
			// Empty spaces everywhere
			G_ScreenBuffer[x][y] = ' ';
			G_ScreenBuffer_Last[x][y] = ' ';

			// Set default foreground colors
			G_ScreenBuffer_Color_FG[x][y] = 8;
			G_ScreenBuffer_Color_FG_Last[x][y] = 8;

			// and background colors
			G_ScreenBuffer_Color_BG[x][y] = 0;
			G_ScreenBuffer_Color_BG_Last[x][y] = 0;
		}
	}
}

// Puts console cursor at new position
void G_SetPosition(int x, int y)
{
	COORD newPosition = {};
	newPosition.X = x;
	newPosition.Y = y;

	SetConsoleCursorPosition(GetStdHandle (STD_OUTPUT_HANDLE), newPosition);
}

// Sets a new foreground color in the console
void G_SetFGColor (WORD color)
{
	if (GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &_CONSOLE_INFO) )
	{
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (_CONSOLE_INFO.wAttributes & 0xF0) + (color & 0x0F) );
	}
}

// Sets a new background color in the console
void G_SetBGColor (WORD color)
{
	if (GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &_CONSOLE_INFO) )
	{
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (_CONSOLE_INFO.wAttributes & 0x0F) | ( (color << 4 ) & 0xF0 ) );
	}
}

// Get the console foreground color
int G_GetFGColor()
{
	return G_GetConsoleColor() & 0x0F;
}

// Get the console background color
int G_GetBGColor()
{
	return (G_GetConsoleColor() >> 4) & 0x0F;
}

// Get the raw console color
int G_GetConsoleColor()
{
	if (GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &_CONSOLE_INFO) )
	{
		return (_CONSOLE_INFO.wAttributes & 0xFF);
	}
	return 0;
}

// Reset console colors to default
void G_ResetColors()
{
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), _CONSOLE_DEFAULTS);
}

// Get console height in characters
int G_GetHeight()
{
	return _CONSOLE_INFO.dwMaximumWindowSize.Y;
}

// Get console width in characters
int G_GetWidth()
{
	return _CONSOLE_INFO.dwMaximumWindowSize.X;
}

// Resets the buffer to the state of last flush
void Draw_RevertBuffer()
{
	int x = 0;
	int y = 0;

	for(x = 0; x < G_DEFAULT_WIDTH; x++)
	{
		for(y = 0; y < G_DEFAULT_HEIGHT; y++)
		{
			G_ScreenBuffer[x][y] = G_ScreenBuffer_Last[x][y];
			G_ScreenBuffer_Color_FG[x][y] = G_ScreenBuffer_Color_FG_Last[x][y];
			G_ScreenBuffer_Color_BG[x][y] = G_ScreenBuffer_Color_BG_Last[x][y];
		}
	}
}

// Draws everything in the buffer on screen
void Draw_FlushBuffer()
{
	int x = 0;
	int y = 0;
	_CONSOLE_HANDLE = GetStdHandle(STD_OUTPUT_HANDLE);

	for(y = 0; y < G_DEFAULT_HEIGHT; y++)
	{
		for(x = 0; x < G_DEFAULT_WIDTH; x++)
		{
			// If nothing has changed
			if(G_ScreenBuffer[x][y] == G_ScreenBuffer_Last[x][y] &&
				G_ScreenBuffer_Color_FG[x][y] == G_ScreenBuffer_Color_FG_Last[x][y] &&
				G_ScreenBuffer_Color_BG[x][y] == G_ScreenBuffer_Color_BG_Last[x][y])
				continue; // Skip

			// Set the cursor position
			G_SetPosition(x, y);

            // Adjust colors
			G_SetFGColor(G_ScreenBuffer_Color_FG[x][y]);
			G_SetBGColor(G_ScreenBuffer_Color_BG[x][y]);

			// write
			char n = G_ScreenBuffer[x][y];
			printf("%c", n);

			// And copy new values into last buffer
			G_ScreenBuffer_Last[x][y] = G_ScreenBuffer[x][y];
			G_ScreenBuffer_Color_FG_Last[x][y] = G_ScreenBuffer_Color_FG[x][y];
			G_ScreenBuffer_Color_BG_Last[x][y] = G_ScreenBuffer_Color_BG[x][y];

		}
	}
	G_SetPosition(0, 0);
}

// Set drawing position
void Draw_SetPos(int x, int y)
{
	// Don't do stuff if positions are out of bounds
	if(x >= G_DEFAULT_WIDTH || y >= G_DEFAULT_HEIGHT || x < 0 || y < 0)
		return;

	_g_current_x = x;
	_g_current_y = y;
}

// Set drawing FG color
void Draw_SetFGColor(WORD color)
{
	_g_current_fgcolor = color;
}

// Set drawing BG color
void Draw_SetBGColor(WORD color)
{
	_g_current_bgcolor = color;
}

// Write character at cursor position
void Draw_Write_Char(char e)
{
	// Write at current position
	G_ScreenBuffer[_g_current_x][_g_current_y] = e;

	// Set colors
	G_ScreenBuffer_Color_FG[_g_current_x][_g_current_y] = _g_current_fgcolor;
	G_ScreenBuffer_Color_BG[_g_current_x][_g_current_y] = _g_current_bgcolor;
}

// Write string at cursor position
void Draw_Write(char *e)
{
	// Get length
	int length = strlen(e);
	int i = 0;

	// for each character
	for(i = 0; i < length; i++)
	{
		// Write char[i] to position
		G_ScreenBuffer[_g_current_x][_g_current_y] = e[i];

		// set colors too!
		G_ScreenBuffer_Color_FG[_g_current_x][_g_current_y] = _g_current_fgcolor;
		G_ScreenBuffer_Color_BG[_g_current_x][_g_current_y] = _g_current_bgcolor;

		// Advance cursor
		_g_current_x++;

		// If we are out of bounds
		if(_g_current_x >= G_DEFAULT_WIDTH)
		{
			// Wrap line
			_g_current_x = 0;
			_g_current_y++;

			// Too many lines?
			if(_g_current_y >= G_DEFAULT_HEIGHT)
				break; // Stop writing
		}
	}
}

// Write in a line, don't wrap
void Draw_Write_Line(int line, char *e)
{
	_g_current_x = 0;
	_g_current_y = line;

	int length = strlen(e);
	int i;

	for(i = 0; i < length; i++)
	{
		// Write char[i] to position
		G_ScreenBuffer[_g_current_x][_g_current_y] = e[i];

		// set colors too!
		G_ScreenBuffer_Color_FG[_g_current_x][_g_current_y] = _g_current_fgcolor;
		G_ScreenBuffer_Color_BG[_g_current_x][_g_current_y] = _g_current_bgcolor;

		// Advance cursor
		_g_current_x++;

		// If we are out of bounds
		if(_g_current_x >= G_DEFAULT_WIDTH)
			break; // stop here, no line wrapping
	}
}

// Write at a position, don't wrap
void Draw_Write_LineAt(int x, int y, char *e)
{
	_g_current_x = x;
	_g_current_y = y;

	int length = strlen(e);
	int i;

	for(i = 0; i < length; i++)
	{
		// Write char[i] to position
		G_ScreenBuffer[_g_current_x][_g_current_y] = e[i];

		// set colors too!
		G_ScreenBuffer_Color_FG[_g_current_x][_g_current_y] = _g_current_fgcolor;
		G_ScreenBuffer_Color_BG[_g_current_x][_g_current_y] = _g_current_bgcolor;

		// Advance cursor
		_g_current_x++;

		// If we are out of bounds
		if(_g_current_x >= G_DEFAULT_WIDTH)
			break; // stop here, no line wrapping
	}
}

// Write a line and fill the rest with spaces
void Draw_Write_Line_Fill(int line, char *e)
{
	_g_current_x = 0;
	_g_current_y = line;

	int length = strlen(e);
	int i;

	for(i = 0; i < G_DEFAULT_WIDTH; i++)
	{
		if(i < length)
		{
			// Write char[i] to position
			G_ScreenBuffer[_g_current_x][_g_current_y] = e[i];
		}
		else
		{
			// Empty space
			G_ScreenBuffer[_g_current_x][_g_current_y] = ' ';
		}

		// set colors too!
		G_ScreenBuffer_Color_FG[_g_current_x][_g_current_y] = _g_current_fgcolor;
		G_ScreenBuffer_Color_BG[_g_current_x][_g_current_y] = _g_current_bgcolor;

		// Advance cursor
		_g_current_x++;

		// If we are out of bounds
		if(_g_current_x >= G_DEFAULT_WIDTH)
			break; // stop here, no line wrapping
	}
}

// Clears the screen, doesn't advance cursor
void Draw_Clear()
{
	int x = 0;
	int y = 0;

	for(x = 0; x < G_DEFAULT_WIDTH; x++)
	{
		for(y = 0; y < G_DEFAULT_HEIGHT; y++)
		{
			// Empty spaces everywhere
			G_ScreenBuffer[x][y] = ' ';
		}
	}
}

// Fills the screen with empty spaces, doesn't advance cursor
void Draw_Fill()
{
	int x = 0;
	int y = 0;

	for(x = 0; x < G_DEFAULT_WIDTH; x++)
	{
		for(y = 0; y < G_DEFAULT_HEIGHT; y++)
		{
			// Empty spaces everywhere
			G_ScreenBuffer[x][y] = ' ';
			G_ScreenBuffer_Color_FG[x][y] = _g_current_fgcolor;
            G_ScreenBuffer_Color_BG[x][y] = _g_current_bgcolor;
		}
	}
}

