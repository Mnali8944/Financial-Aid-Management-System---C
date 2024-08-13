#include <stdio.h>
#include <stdlib.h>

void display(int inc[], int exp[], int max_count); 
void joblist();

int main() {
    int index;

    printf("Enter the Favourite Group ID number\n");
    printf("HINT: If you choose your number as 30, then you can see the MAGIC\n");

    scanf("%d", &index);
    if(index == 30) {
        printf("\t\t\t\t\t\tHELLO! \n\n\tY_O_U   A_R_E   E_N_T_E_R_I_N_G   T_O   T_H_E   B_U_D_G_E_T_I_N_G   E_M_P_O_W_E_R_M_E_N_T   T_O_O_L \n");
        printf("\n");
        printf("\t\t\t\t\tTool Creator : M.N.M. NUSRATH ALI PS/2021/237; \n\t\t\t\t\tMy Solo Partner : A.M.F.MARFA PE/2021/038. \n");
    } else {
        printf("\tCAUTION : SORRY, THIS IS ONLY ALLOWED FOR FAN OF GROUP NUMBER 30 \n");
        return 0;
    }
    printf("\n");
    printf("\t\t------------------------------------------------------\n");

    int inc_count = 0, exp_count = 0;
    FILE *inc_fp, *exp_fp;

    inc_fp = fopen("./income.txt", "w");
    exp_fp = fopen("./expense.txt", "w");

    if(inc_fp == NULL || exp_fp == NULL) {
        printf("File is not recognized\n");
        return 1;
    }

    int inc[100] = {100, 200, 300, 400, 500, 600, 800, 400, 1000, 900};
    int exp[100] = {110, 200, 300, 440, 550, 800, 750, 1000, 675};

    for(int i = 0; i < 10 ; i++) {
        fprintf(inc_fp, "%d\n", inc[i]);
    }

    for(int i = 0; i < 9; i++) {
        fprintf(exp_fp, "%d\n", exp[i]);
    }

    fclose(inc_fp);
    fclose(exp_fp);

    inc_fp = fopen("./income.txt", "r");
    exp_fp = fopen("./expense.txt", "r");
    
    while(fscanf(inc_fp, "%d", &inc[inc_count]) != EOF) {
        inc_count++;
    }

    while(fscanf(exp_fp, "%d", &exp[exp_count]) != EOF) {
        exp_count++;
    }

    fclose(inc_fp);
    fclose(exp_fp);

    int max_count = (inc_count > exp_count) ? inc_count : exp_count;

    printf("\t\t|Income\t|Expense\t|Budget\t\t|{Favorable(+)/Adverse(-)}\n");
    printf("\t\t-------------------------------------------------------\n");

    display(inc, exp, max_count);

    int sum_inc = 0, sum_exp = 0;
    for(int i = 0; i < inc_count; i++) {
        sum_inc += inc[i];
    }
    for(int i = 0; i < exp_count; i++) {
        sum_exp += exp[i];
    }
    int sum_bud = sum_inc - sum_exp;
    printf("\t       ________________________________________________________\n");
    printf("Gross Amount : |%d\t|%d\t\t|%d\n", sum_inc, sum_exp, sum_bud);

    printf("\n\tThank You For Joining With Us\n\tStay Tuned>>>>>\n");

    joblist();

    return 0;
}

void display(int inc[], int exp[], int max_count) {
    for(int i = 0; i < max_count; i++) {
        int budget = inc[i] - exp[i];
        char defect = (budget >= 0) ? 'F' : 'A';
        printf("\t\t|%d\t|%d\t\t|%d\t\t|%c\n", inc[i], exp[i], budget, defect);
    }
}

void joblist() {
    int work;
    char sub;		
    int entry;

    printf("\n\n\n\n");
    printf("Do you want to identify the Job you are interested in?  YES OR NO, \n\t if 'YES' enter '1' else enter any integer\n");
    scanf("%d", &entry);

    if(entry == 1) {
        printf("\t\t\t\tWELCOME!\n\t\tOn Campus Job Opportunities\n");
        printf("\t\t\tAuthor: A.M.F. MARFA =======STUDENT_ID- PE/2021/038\n");
        printf("\t\t\tPartner:M.N.M. NUSRATH ALI =======STUDENT_ID- PS/2021/237\n");
        printf("\n\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<MAIN CATEGORIES>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("\t\t1.Graphics and Design\n\t\t2.Video and Animation\n\t\t3.Writing and Translation\n\t\t4.Data\n\t\t5.Photography\n");
    } else {
        printf("\t Try Again!!!!!! \n");
        exit(0);
    }

    printf("\n");
    printf("\tEnter your work from 1,2,3,4 and 5 of the Main Category of Job list\n");
    scanf("%d", &work);

    getchar();  // Consume the newline left in the buffer

    switch(work) {
        case 1:
            printf("\t<<<<<<<<<<<<<<<<<<<<<<<<SUB CATEGORIES>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
            printf("\tYour main selection is : Graphics and Design\n");
            printf("\t\tSUB CATEGORIES : \n");
            printf("\t\t\ta. Logo design\n\t\t\tb. Website design\n\t\t\tc. Image editing\n\t\t\td. Brochure Design\n\t\t\te. Presentation design\n");

            printf("\tEnter your character a, b, c, d and e sub category of job list\n");
            scanf("%c", &sub);
            switch(sub) {
                case 'a':
                    printf("\tFinally you select your job pattern : Logo design\n\t\t Your selection Pathway>>>>>>\tGRAPHIC DESIGN --> LOGO DESIGN\n");
                    break;
                case 'b':
                    printf("\tFinally you select your job pattern : Website design\n\t\t Your selection Pathway>>>>>>\tGRAPHIC DESIGN --> WEBSITE DESIGN\n");
                    break;
                case 'c':
                    printf("\tFinally you select your job pattern : Image editing\n\t\t Your selection Pathway>>>>>>\tGRAPHIC DESIGN --> IMAGE EDITING\n");
                    break;
                case 'd':
                    printf("\tFinally you select your job pattern : Brochure design\n\t\t Your selection Pathway>>>>>>\tGRAPHIC DESIGN --> BROCHURE DESIGN\n");
                    break;
                case 'e':
                    printf("\tFinally you select your job pattern : Presentation design\n\t\t Your selection Pathway>>>>>>\tGRAPHIC DESIGN --> PRESENTATION DESIGN\n");
                    break;
                default:
                    printf("\tInvalid Subcategory selection\n");
                    break;
            }
            break;
        // Other cases remain the same
        // ...

        default:
            printf("\tInvalid Main category selection\n");
            break;
    }
    printf();
}