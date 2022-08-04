#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int randomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int choice(char you, char computer)
{
    if (you == computer)
    {
        return -1;
    }

    if (you == 'r' && computer == 's')
    {
        return 1;
    }
    else if (you == 's' && computer == 'r')
    {
        return 0;
    }

    if (you == 's' && computer == 'p')
    {
        return 1;
    }
    else if (you == 'p' && computer == 's')
    {
        return 0;
    }

    if (you == 'p' && computer == 'r')
    {
        return 1;
    }
    else if (you == 'r' && computer == 'p')
    {
        return 0;
    }
}

int main()
{
    char you, computer, retry;
    int playerScore = 0, computerScore = 0, temp;
    char dict[] = {'r', 'p', 's'};
start:
    printf("\n\n<<<<<<<<<< Welcome to the Rock, Paper, Scissor >>>>>>>>>> \n");

    for (int i = 0; i < 3; i++)
    {
        printf("\nYour turn:\n");
        printf(">>> Choose '1' for Rock, '2' for Paper and '3' for Scissors\n");
        scanf("%d", &temp);
        getchar();
        you = dict[temp - 1];
        printf("You chooses %c\n", you);

        printf("\nComputer's turn:\n");
        printf(">>> Choose '1' for Rock, '2' for Paper and '3' for Scissors\n");
        temp = randomNumber(3) + 1;
        computer = dict[temp - 1];
        printf("Computer chooses %c\n", computer);

        if (choice(computer, you) == 1)
        {
            computerScore += 1;
            printf("\nComputer got it! \n\n");
        }
        else if (choice(computer, you) == -1)
        {
            playerScore += 1;
            computerScore += 1;
            printf("\nIt is draw \n\n");
        }
        else
        {
            playerScore += 1;
            printf("\nYou got it! \n\n");
        }
        printf("\nYou: %d\nComputer: %d\n", playerScore, computerScore);
    }

    if (playerScore > computerScore)
    {
        printf("\nYou win! \n");
    }
    else if (playerScore < computerScore)
    {
        printf("\nComputer win! \n");
    }
    else
    {
        printf("\nMatch draw\n");
    }

    printf("\n\nPress 'r' for replay and press 'q' for quit\n\n");
    scanf("%c", &retry);
    switch (retry)
    {
    case 'r':
        system("CLS");
        playerScore = 0;
        computerScore = 0;
        goto start;
        break;

    case 'q':
        goto end;
        break;

    default:
        break;
    }
end:

    return 0;
}