#include "grafiki1.h"
//#include "kalkulyator.h"


int SDL_main(int argc, char* argv[]) {
    SDL_SetWindowMinimumSize(w.w, 500, 250);
    //SDL_SetWindowMaximumSize(w.w, 1200, 600);
    while (re_menu >= 0) {
        if (re_menu == 0) {
            win1::grafiki();
            win1::run = 1;
            re_menu = 0;
        }
        /*if (re_menu == 1) {
            win2::grmain();
            win2::run = 1;
        }*/
    }


    SDL_Quit();
    return 0;
}

