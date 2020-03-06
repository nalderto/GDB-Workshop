#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tweet.h"

void reply(Tweet *parent_tweet, char* body) {
    while (parent_tweet->reply != NULL) {
        parent_tweet = parent_tweet->reply;
    }
    Tweet *new_tweet = malloc(sizeof(Tweet));
    strcpy(new_tweet->body, body);
    new_tweet->reply = NULL;
    parent_tweet->reply = new_tweet;
    return;
}

void print_replies(Tweet *tweet) {
    printf("\033[0;36m");
    while (tweet != NULL) {
        printf("%s\n", tweet->body);
        if (tweet->reply != NULL) {
            printf("|\n");
            printf("|\n");
        }
        tweet = tweet->reply;
    }
    printf("\033[0m");
    return;
}

void free_tweet(Tweet *tweet) {
    while(tweet != NULL) {
        Tweet *next = tweet->reply;
        free(tweet);
        tweet = next;
    }
}
