#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TWEET_SIZE (140)

typedef struct tweet {
    char body[TWEET_SIZE];
    struct tweet *reply;
} Tweet;

void reply(Tweet *parent_tweet, char* body);
void print_replies(Tweet *tweet);
void free_tweet(Tweet *tweet);
