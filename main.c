#include "tweet.h"

int main(char* argv, int argc) {
    Tweet *main_tweet = malloc(sizeof(Tweet));
    strcpy(main_tweet->body, "Hello and thank you for comming to the GDB/Vim Workshop! "
        "We all really hope that you find it to be a worthy learning experience!");
    main_tweet->reply = NULL;
    printf("Welcome to bootleg Twitter!  Select one of the following options:\n");
    while (1) {
        printf("0) Print Tweets\n1) Reply to Tweet\n2) Exit\n");
        int input = 0;
        scanf("%d", &input);
        getchar();
        if (input == 0) {
            print_replies(main_tweet);
        }
        else if (input == 2) {
            break;
        }
        else if (input == 1) {
            char input_tweet[TWEET_SIZE];
            printf("Input your reply tweet: ");
            fgets(input_tweet, TWEET_SIZE, stdin);
            char* pch = strtok(input_tweet, "\n");
            reply(main_tweet, pch);
        }

        else {
            printf("Invalid Input!\n");
        }
    }
    return 0;
}
