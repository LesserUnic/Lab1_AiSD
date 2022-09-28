#include<iostream>
#include<stdio.h>
#include"List.h"
int
main ()
{
  int command = 0;
  list *A = new list;
  list *B = new list;
  std::cout << "Choose size of list A:";
  int a_size;
  std::cin >> a_size;
  std::cout << "Choose size of list B:";
  int b_size;
  std::cin >> b_size;
  for (int i = 0; i < a_size; i++)
    {
      A->make_new ();
      A->current->data1->data = rand () % 10;
    }
  for (int i = 0; i < b_size; i++)
    {
      B->make_new ();
      B->current->data1->data = rand () % 10;
    }

  char lists;
  while (true)
    {
      std::cout << "Choose list A or B for the next doing:";
      std::cin >> lists;
      //system("clear");
      std::cout << "1)Add element at the end of list\n";
      std::cout << "2)Add element at the begining of list\n";
      std::cout << "3)Delete last element of list\n";
      std::cout << "4)Delete first element of list\n";
      std::cout << "5)Add element at the index in the list\n";
      std::cout << "6)Get info about element of list\n";
      std::cout << "7)Delete element at the index in the list\n";
      std::cout << "8)Get size of list\n";
      std::cout << "9)Delete all elements of list\n";
      std::cout << "10)Replace element in the list\n";
      std::cout << "11)Check list on emptiness\n";
      std::cout << "12)Compare lists\n";
      std::cout << "13)View elements both of lists\n";
      std::cout << "Enter command:";

      std::cin >> command;
      int tmp = 0;
      if (lists == 'A')
	{
	  switch (command)
	    {
	    case 1:
	      A->add_to_end ();
	      break;
	    case 2:
	      A->add_to_beg ();
	      break;
	    case 3:
	      A->del_last ();
	      break;
	    case 4:
	      A->del_first ();
	      break;
	    case 5:
	      std::cout << "Enter index:";
	      std::cin >> tmp;
	      A->add_to_index (tmp);
	      break;
	    case 6:
	      std::cout << "Enter index:";
	      std::cin >> tmp;
	      A->get_info_to_index (tmp);
	      break;
	    case 7:
	      std::cout << "Enter index:";
	      std::cin >> tmp;
	      A->del_to_index (tmp);
	      break;
	    case 8:
	      A->get_len ();
	      break;
	    case 9:
	      A->del_all ();
	      break;
	    case 10:
	      std::cout << "Enter index:";
	      std::cin >> tmp;
	      A->replace_to_index (tmp);
	      break;
	    case 11:
	      A->check ();
	      break;
	    case 12:
	      compare_list (A, B);
	      break;
	    case 13:
	      A->view_all ();
	      std::cout << std::endl;
	      B->view_all ();
	      break;
	    default:
	      return 0;
	    }
	}
      if (lists == 'B')
	{
	  switch (command)
	    {
	    case 1:
	      B->add_to_end ();
	      break;
	    case 2:
	      B->add_to_beg ();
	      break;
	    case 3:
	      B->del_last ();
	      break;
	    case 4:
	      B->del_first ();
	      break;
	    case 5:
	      std::cout << "Enter index:";
	      std::cin >> tmp;
	      B->add_to_index (tmp);
	      break;
	    case 6:
	      std::cout << "Enter index:";
	      std::cin >> tmp;
	      B->get_info_to_index (tmp);
	      break;
	      break;
	    case 7:
	      std::cout << "Enter index:";
	      std::cin >> tmp;
	      B->del_to_index (tmp);
	      break;
	    case 8:
	      B->get_len ();
	      break;
	    case 9:
	      B->del_all ();
	      break;
	    case 10:
	      std::cout << "Enter index:";
	      std::cin >> tmp;
	      B->replace_to_index (tmp);
	      break;
	    case 11:
	      B->check ();
	      break;
	    case 12:
	      compare_list (B, A);
	      break;
	    case 13:
	      A->view_all ();
	      std::cout << std::endl;
	      B->view_all ();
	      break;
	    default:
	      return 0;
	    }
	}

    }

}
