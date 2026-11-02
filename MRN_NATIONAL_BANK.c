#include <stdio.h>

int main() {

    int choice ;
    int Main_Account = 700007 ;
    int balance = 50000 ;
    int withdraw_limit = 20000 ;
    int new_limit = 0 ;
    //deposit variables
    int deposit_amount = 0 ;
    int total_deposit = 0 ;
    int deposit_count = 0 ;
    //withdraw variables
    int pin_num = 2026 ;
    int pin ;
    int pin_tries = 3 ;
    int withdraw_amount = 0 ;
    int total_withdraw = 0 ;
    int withdraw_count = 0 ;
    //Transfer variables
    int transfer_amount = 0 ;
    int total_transfer = 0 ;
    int transfer_count = 0 ;
    int alt_account ;
    // Total Transaction Count
    int Total_transaction = 0 ;

   //Initial Info Menu
   printf("================================================\n\t\tMRN NATIONAL BANK\n\t\t DIGITAL VAULT\n================================================\n\n");
   printf("\t\tWelcome, Mrn!\n");
   printf("\n\t\tAccount: 700007\n");
   printf("\t\tStatus: ACTIVE\n");
   printf("\n------------------------------------------------\n");

   do{
   //Main Menu
   printf("\n\t\t MAIN MENU\n");
   printf("\n\t  [1] Account Overview\n");
   printf("\t  [2] Deposit Funds\n");
   printf("\t  [3] Withdraw Funds\n");
   printf("\t  [4] Transfer Money\n");
   printf("\t  [5] Transaction Statistics\n");
   printf("\t  [6] Account Settings\n");
   printf("\t  [7] Exit Terminal\n");
   printf("\n------------------------------------------------\n");
   main_reset :
   printf("\t  Select Your Service: ");
   scanf("%d",&choice);

   //switch-Case Set-up
   Total_transaction = deposit_count + withdraw_count + transfer_count;

   switch(choice)
   {
      //Case 1 --- Account Overview
      case 1 :
      printf("\n================================================\n");
      printf("\t\tACCOUNT OVERVIEW\n");
      printf("================================================\n");
      printf(" Account Holder : Mrn\n");
      printf(" Account Number : 700007\n");
      printf(" Account Type   : Premium Savings\n");
      printf(" Account Status : ACTIVE\n");
      printf("\n Available Balance : %d BDT\n",balance);
      printf(" Daily Withdrawal Limit : %d BDT\n",withdraw_limit);
      printf("\n================================================\n");
      break;

      //case 2 -- Deposit Funds
      case 2 :
      printf("\n================================================\n");
      printf("\t\tDEPOSIT FUNDS\n");
      printf("================================================\n");
      dep_res :
      printf("\nEnter Deposit Amount: ");
      scanf("%d",&deposit_amount);
      if(deposit_amount>0)
      {
        printf("\nProcessing Transaction...\n");
        printf("\n[SUCCESS] Deposit Completed!\n");
        printf("\nPrevious Balance : %d BDT\n",balance);
        balance += deposit_amount ;
        printf("Deposited Amount : %d BDT\n",deposit_amount);
        printf("New Balance      : %d BDT\n",balance);
        total_deposit += deposit_amount ;
        printf("Total Deposited: %d BDT\n",total_deposit);
        deposit_count++ ;
        printf("Successful Deposit Count : %d\n",deposit_count);
        printf("\n================================================\n");

      }else{
        printf("Invalid Amount!\n");
        goto dep_res ;
      }
      break;

      //case 3 --- Withdraw

      case 3 :
      if(withdraw_limit != 0)
      {
      printf("\n================================================\n");
      printf("\t\tWITHDRAW FUNDS\n");
      printf("================================================\n");
      printf("\nSecurity Verification Required.\n");
      while(1){ //Dont Worry About infinite Loop Mrn is Handling It :)
        printf("\nEnter Your PIN: ");
        scanf("%d",&pin);
        if(pin == pin_num)
        {
            inval_witd :
            printf("\nEnter Withdrawal Amount: ");
            scanf("%d",&withdraw_amount);
            if(withdraw_amount>0 && withdraw_amount<=balance && withdraw_amount <= withdraw_limit && balance !=0)
            {
              printf("\n[TRANSACTION SUCCESSFUL]\n");
              printf("Previous balance: %d BDT\n",balance);
              printf("Withdrawn Amount: %d BDT\n",withdraw_amount);
              balance -= withdraw_amount ;
              total_withdraw += withdraw_amount ;
              withdraw_count ++ ;
              printf("Remaining Balance: %d BDT\n",balance);
              withdraw_limit -= withdraw_amount ;
              printf("\nDaily Limit Remaining: %d BDT\n",withdraw_limit);
              break;

            }else{
                printf("INVALID :)\n");
                goto inval_witd ;
            }
        }else if(pin != pin_num)
        {
            pin_tries-- ;
            if(pin_tries>0)
            {
            printf("INVALID PIN\n");
            printf("Attempts Remaining: %d\n",pin_tries);
            }else{
            printf("[ACCESS DENIED]\n");
            printf("\nMaximum PIN attempts exceeded.\n");
            printf("\nReturning to Main Menu...\n");
            break;
        }
        }
    }
    }else{
        printf("\n\t!!! DAILY WITHDRAW LIMIT REACHED :)\n");
    }
    break;

    // Case 4 --- Transfering Funds
    case 4 :
      printf("\n================================================\n");
      printf("\t\tMONEY TRANSFER\n");
      printf("================================================\n");
      alt_acc_res : //MRN BANK IS WAY TO GENEROUS ABOUT CUSTOMERS WRONG/INVALID INPUTS LOL :)
      printf("\nEnter Recipient Account Number: ");
      scanf("%d",&alt_account);
      if(alt_account == Main_Account)
      {
        printf("CAN'T BE Same As USER's Account :)\n");
        goto alt_acc_res ;
      }
      printf("\nSecurity Verification Required.\n");
      while(1){
        printf("\nEnter Your PIN: ");
        scanf("%d",&pin);
        if(pin == pin_num)
        {
            inval_transfer :
            printf("\nEnter Transfer Amount: ");
            scanf("%d",&transfer_amount);
            if(transfer_amount>0 && transfer_amount<=balance && balance !=0)
            {
              printf("\nProcessing Transfer...\n");
              printf("\n[SUCCESS] Transfer Completed!\n");
              printf("\nRecipient Account : %d\n",alt_account);
              printf("Transfer Amount   : %d BDT\n",transfer_amount);
              balance -= transfer_amount ;
              total_transfer += transfer_amount ;
              transfer_count ++ ;
              printf("Remaining Balance: %d BDT\n",balance);
              printf("\n================================================\n");
              break;

            }else{
                printf("INVALID :)\n");
                goto inval_transfer ;
            }
        }else if(pin != pin_num)
        {
            pin_tries-- ;
            if(pin_tries>0)
            {
            printf("INVALID PIN\n");
            printf("Attempts Remaining: %d\n",pin_tries);
            }else{
            printf("[ACCESS DENIED]\n");
            printf("\nMaximum PIN attempts exceeded.\n");
            printf("\nReturning to Main Menu...\n");
            break;
        }
        }
      }
      break;

      //case 5 - Transaction TRANSACTION STATISTICS
      case 5 :
      printf("\n================================================\n");
      printf("\t\tTRANSACTION REPORT\n");
      printf("================================================\n");
      printf("\nTotal Deposits      : %d BDT\n",total_deposit);
      printf("Total Withdrawals   : %d BDT\n",total_withdraw);
      printf("Total Transfer's      : %d BDT\n",total_transfer);
      printf("\nSuccessful Transactions: %d\n",Total_transaction);
      printf("\nCurrent Balance: %d BDT\n",balance);
      printf("\n================================================\n");
      break;

      //case 6 ---
      case 6 :
      printf("\n================================================\n");
      printf("\t\tACCOUNT SETTINGS\n");
      printf("================================================\n");
      printf("\nCurrent Daily Withdraw Limit: %d BDT\n",withdraw_limit);
      lim_res :
      printf("Enter New Daily Limit: ");
      scanf("%d",&new_limit);
      if(new_limit<=0){
        printf("\nINVALID AMOUNT (-_-)\n");
        goto lim_res ;
      }
      withdraw_limit = new_limit ; //This new limit overrides aka resets all daily limits to max It's a design choice btw
      printf("\n[SUCCESS] Withdrawal Limit Updated!\n");
      printf("\n================================================\n");
      break;

      //Case 7
      case 7 :
      printf("\n================================================\n");
      printf("\n\tTHANK YOU FOR BANKING WITH\n");
      printf("\n\t     MRN NATIONAL BANK\n");
      printf("\n\tYour Trust Our Priority (^_^)\n");
      printf("\n================================================\n");
      printf("\n\tTERMINAL SHUTDOWN...\n\n");
      break;

      default :
      printf("\t  INVALID CHOICE MATE :)\n");
      goto main_reset ;

   }}while(choice!=7);

    return 0; // Thank You Mate For Reading My Code :)
}
