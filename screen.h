enum COLOR(BLACK=30,RED,GREEN,YELLOW, MAGENTA,CYAN,WHITE);
#define bg(c) (c+10)
#define COL 80
#define BAR "\u2620"
// function declarations
void clearScreen(void);
void setColors(short, short);
void resetColors(void);
void barChart(int []);
