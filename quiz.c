#include <stdio.h>
#include <stdlib.h>

#define TOTAL 25

struct Question {
    char question[300];
    char options[4][150];
    int correct;
};

void startQuiz();

struct Question q[TOTAL] = {
    // ---------------- INTERFERENCE (1–9) ----------------
    {"1. Fringe width in YDSE is:", 
     {"1) lambda D / d","2) d / lambda D","3) lambda d / D","4) D / lambda d"}, 1},

    {"2. Central fringe in YDSE is:", 
     {"1) Dark","2) Bright","3) Colored","4) Invisible"}, 2},

    {"3. Condition for constructive interference is:", 
     {"1) Path difference = n lambda",
      "2) Path difference = (2n+1) lambda/2",
      "3) Path difference = lambda/4",
      "4) Path difference = 0 only"}, 1},

    {"4. Phase shift pi occurs when reflection is from:", 
     {"1) Rarer to denser","2) Denser to rarer","3) Same medium","4) Vacuum"}, 1},

    {"5. Newton's rings are formed due to:", 
     {"1) Diffraction","2) Interference","3) Polarization","4) Refraction"}, 2},

    {"6. Central spot in Newton's rings is:", 
     {"1) Bright","2) Dark","3) Colored","4) Absent"}, 2},

    {"7. Anti-reflection coating works on principle of:", 
     {"1) Refraction","2) Polarization","3) Destructive interference","4) Diffraction"}, 3},

    {"8. Fringe width increases if:", 
     {"1) d increases","2) D decreases","3) lambda increases","4) lambda decreases"}, 3},

    {"9. Path difference for first dark fringe is:", 
     {"1) lambda","2) lambda/2","3) 2 lambda","4) lambda/4"}, 2},

    // ---------------- DIFFRACTION (10–17) ----------------
    {"10. First minimum in single slit diffraction occurs when:", 
     {"1) a sin(theta) = lambda",
      "2) a sin(theta) = 2 lambda",
      "3) a cos(theta) = lambda",
      "4) a = lambda"}, 1},

    {"11. Central maximum in diffraction is:", 
     {"1) Narrow","2) Same as others","3) Broad and intense","4) Absent"}, 3},

    {"12. Resolving power of grating is proportional to:", 
     {"1) 1/N","2) N","3) lambda","4) slit width"}, 2},

    {"13. Grating equation is:", 
     {"1) d sin(theta)=n lambda",
      "2) d cos(theta)=n lambda",
      "3) a sin(theta)=lambda",
      "4) n sin(theta)=d lambda"}, 1},

    {"14. Diffraction is significant when slit width is:", 
     {"1) Very large","2) Comparable to wavelength","3) Zero","4) Infinite"}, 2},

    {"15. Intensity at minima is:", 
     {"1) Maximum","2) Zero","3) Half","4) Infinite"}, 2},

    {"16. Angular width of central maximum is:", 
     {"1) lambda/a","2) a/lambda","3) lambda D","4) d/lambda"}, 1},

    {"17. Fraunhofer diffraction occurs when source is:", 
     {"1) Very near","2) At infinity","3) Inside slit","4) Behind screen"}, 2},

    // ---------------- POLARIZATION (18–25) ----------------
    {"18. Light is transverse because it shows:", 
     {"1) Refraction","2) Interference","3) Polarization","4) Diffraction"}, 3},

    {"19. Brewster angle formula:", 
     {"1) tan(theta_p)=n",
      "2) sin(theta)=n",
      "3) cos(theta)=n",
      "4) theta=90"}, 1},

    {"20. At Brewster angle, reflected and refracted rays are:", 
     {"1) Parallel","2) Perpendicular","3) Same","4) Random"}, 2},

    {"21. Malus Law is:", 
     {"1) I=I0 sin(theta)",
      "2) I=I0 cos(theta)",
      "3) I=I0 cos^2(theta)",
      "4) I=I0 tan(theta)"}, 3},

    {"22. Quarter wave plate introduces phase difference of:", 
     {"1) pi","2) pi/2","3) 2pi","4) pi/4"}, 2},

    {"23. Half wave plate introduces phase difference of:", 
     {"1) pi","2) pi/2","3) pi/4","4) 2pi"}, 1},

    {"24. Polarization by reflection occurs at:", 
     {"1) Critical angle","2) Brewster angle","3) 90 deg","4) 0 deg"}, 2},

    {"25. Polaroids are used in:", 
     {"1) LCD","2) Sunglasses","3) 3D movies","4) All of these"}, 4}
};

int main() {
    startQuiz();
    return 0;
}

void startQuiz() {
    int score = 0, ans;

    printf("\n===== WAVE OPTICS QUIZ (25 QUESTIONS) =====\n");

    for(int i = 0; i < TOTAL; i++) {
        printf("\n%s\n", q[i].question);

        for(int j = 0; j < 4; j++)
            printf("%s\n", q[i].options[j]);

        printf("Enter answer (1-4): ");
        
        // --- Added Input Validation ---
        if (scanf("%d", &ans) != 1) {
            printf("Error: Please enter a number (1, 2, 3, or 4).\n");
            while(getchar() != '\n'); // Clears the bad input from memory
            i--; // Asks the same question again
            continue;
        }

        if(ans == q[i].correct) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! Correct answer: Option %d\n", q[i].correct);
        }
    }

    printf("\n===== QUIZ COMPLETED =====\n");
    printf("Final Score: %d/%d\n", score, TOTAL);
    printf("Percentage: %.2f%%\n", (score * 100.0) / TOTAL);

    if(score >= 20)
        printf("Result: Excellent mastery of Wave Optics.\n");
    else if(score >= 12)
        printf("Result: Good understanding, revise numericals.\n");
    else
        printf("Result: Needs serious revision.\n");
}