#include "stdio.h"

// Enum that contains the different ranges of ranks and their values is the amount of required stars
typedef enum
{
  R25_21 = 2,
  R20_16 = 3,
  R15_11 = 4,
  R10_1 =  5,
  LEGEND = 0
} RankRange;

// Takes a rank and returns the range as the RankRank enum
RankRange getRange(unsigned char rank);

int main()
{
    char matchResult; // W or L

    // Important data of the game
    unsigned char rank   = 25,
                  stars  = 0,
                  streak = 0;

    // Current range of ranks the player is in, starts at 25-21
    RankRange currentRange = R25_21;

    // Read until End Of File
    while ((matchResult = getc(stdin)) != EOF)
    {
        if (rank == 0) {continue;} // If legend, skip everything


        currentRange = getRange(rank); // Update range

        if (matchResult == 'W') // Win!
        {
            // Increment stars and streak, always happens upon victory.
            stars++;
            streak++;

            // Bonus stars according to requirements
            if (rank > 5 && streak > 2) {stars++;}

            // Promotion!
            if (stars > currentRange)
            {
                rank--; // Rank up

                // Stars calculated. In summary. When your stars are above the range, just remove the your current required stars.
                // The remaining are the stars that continue to the next rank
                stars = stars - currentRange; 
            }
        }
        else if (matchResult == 'L') // Defeat!
        {
            streak = 0; // Rest streak

            if (stars == 0) // No stars remaining, demotion!
            {
                // These ranks (Legend = 0) will have no effect
                if (rank == 20 || rank == 0 || rank == 25) {continue;}

                // Get the range of the rank that the player will demote to (used to calculate stars in the demoted rank)
                RankRange previousRange = getRange(rank + 1);
                rank++; // Rank down
                
                stars = previousRange - 1;
            }
            else if (rank < 21) // If rank is above 20 then reduce stars
            {
                stars--;
            }
        }
    }

    // Printing the rank
    if (rank != 0)
        printf("%d", rank);
    else
        printf("Legend");

    return 0;
}

RankRange getRange(unsigned char rank)
{
    // This is a stepping ladder. If the previous is not returning it must in the range between previous and next.
    // If none are returning then we are the top. THE LEGENDARY RANK!!!

    if (rank > 20) {return R25_21;}
    if (rank > 15) {return R20_16;}
    if (rank > 10) {return R15_11;}
    if (rank > 0)  {return R10_1;}
    return LEGEND;
}