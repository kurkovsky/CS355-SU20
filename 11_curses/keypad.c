// how to capture keyboard input using curses

#include <curses.h>

int main() {
    initscr();              // initialize the curses library
    clear();                // clear the screen
    curs_set(0);            // hide the cursor
    noecho();               // do not echo the user input to the screen
    keypad(stdscr,TRUE);    // enables working with the arrow keys
    move(0,0);
    addstr("Press any key...");
    while(1) {
        int ch=getch();
        char buf[100];
        move(0,0);
        sprintf(buf,"The screen is %d rows by %d column", LINES, COLS);
        addstr(buf);
        move(1,0);
        switch(ch){
            case KEY_UP:
                addstr("You pressed the UP arrow                  ");
                break;
            case KEY_DOWN:
                addstr("You pressed the DOWN arrow                  ");
                break;
            case KEY_LEFT:
                addstr("You pressed the LEFT arrow                  ");
                break;
            case KEY_RIGHT:
                addstr("You pressed the RIGHT arrow                  ");
                break;
            case 'x':       // pressing 'x' or 'X' will exit teh program
            case 'X':
                endwin();   // close curses
                return 0;
            default:
                sprintf(buf,"You pressed a \"%c\" key, ASCII code %d", (char)ch, ch);  
                addstr(buf);
                break;
        }
    }
}