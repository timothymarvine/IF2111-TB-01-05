if(manual_strcmp(command, 10) == 0){
                helpinmain();
            }else if (manual_strcmp(command, 9) == 0) {
                printf("\nExiting program...\n");
                running = 0;
            }else if (manual_strcmp(command, 2) == 0){
                workChallenge(&uang_asal);
            }else {
                printf("\nInvalid command. Please try again.\n");
            }