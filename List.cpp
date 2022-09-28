#include "List.h"
void
list::make_new ()                           //Making new node
{
  if (head == nullptr)
    {
      head = new list;
      head->data1 = new info;
      current = head;
      last = current;
    }
  else
    {
      current = head;
      while (current->next != nullptr)
	{
	  current = current->next;
	}
      current->next = new list;
      current->next->prev = current;
      current = current->next;
      current->data1 = new info;
      last = current;
    }

}				

void
list::get_info ()                               //Output info from cell
{
  std::cout << current->data1->data << ' ';
}				

void
list::put_info ()                               //Input info to cell
{
  std::cout << "Enter number:";
  std::cin >> current->data1->data;
}				

void
list::add_to_end ()                             //Add element to end of the list
{
  current = last;
  current->next = new list;
  current->next->prev = current;
  current = current->next;
  current->data1 = new info;
  put_info ();
  last = current;
}

void
list::add_to_beg ()                             //Add element to beginig of the list
{
  list *tmp = new list;
  tmp->data1 = new info;
  head->prev = tmp;
  tmp->next = head;
  head = tmp;
  current = head;
  put_info ();
}

void
list::del_last ()                               //Delete last element
{
  current = last;
  current->prev->next = nullptr;
  current->prev = nullptr;
  delete current->data1;
  delete current;
}

void                                            //Delete the first element
list::del_first ()
{
  current = head;
  head = current->next;
  current->next = nullptr;
  delete current->data1;
  delete current;
}

void                                            //Add element to index of the list
list::add_to_index (int index)
{
  current = head;
  for (int i = 0; i < index; i++)
    {
      if (current->next != nullptr)
	{
	  current = current->next;
	}
      else
	{
	  std::cout << "Wrong request" << std::endl;
	  break;
	}
    }
  if (index == 0 or current->next == nullptr)
    {
      if (current->next == nullptr)
	{
	  add_to_end ();
	}
      else
	{
	  add_to_beg ();
	}
    }
  else
    {
      list *tmp = new list;
      tmp->data1 = new info;
      tmp->next = current;
      tmp->prev = current->prev;
      current->prev->next = tmp;
      current->next->prev = tmp;
      current = tmp;
      put_info ();
    }
}

void
list::del_to_index (int index)
{
  current = head;
  for (int i = 0; i < index; i++)
    {
      if (current->next != nullptr)
	{
	  current = current->next;
	}
      else
	{
	  std::cout << "Wrong request" << std::endl;
	  break;
	}
    }
  if (index == 0 or current->next == nullptr)
    {
      if (current->next == nullptr)
	{
	  del_last ();
	}
      else
	{
	  del_first ();
	}
    }
  else
    {
      current->prev->next = current->next;
      current->next->prev = current->prev;
      delete current->data1;
      delete current;
      current = head;
    }
}

int
list::get_len ()
{
  current = head;
  int num = 0;
  while (current->next != nullptr)
    {
      current = current->next;
      num++;
    }
  current = head;
  return num + 1;
}

void
list::del_all ()
{
  current = last;
  while (head != current)
    {
      del_last ();
      current = last;
    }
  delete head->data1;
  head = nullptr;
}

void
list::replace_to_index (int index)
{
  current = head;
  for (int i = 0; i < index; i++)
    {
      if (current->next != nullptr)
	{
	  current = current->next;
	}
      else
	{
	  std::cout << "Wrong request" << std::endl;
	  break;
	}
    }
  put_info ();
}

bool
list::check ()
{
  if (head == nullptr)
    {
      return true;
    }
  else
    {
      return false;
    }
}				//check list in emptyness

int
compare_list (list * A, list * B)
{
  A->current = A->head;
  B->current = B->head;
  list *tmp = new list;
  int s = B->get_len ();
  for (int i = 0; i < s; i++)                               //Copy list, which elements we try to find in other list
    {
      tmp->make_new ();
      tmp->current->data1->data = B->current->data1->data;
      B->current = B->current->next;
    }

  tmp->current = tmp->head;

  int m = A->get_len ();
  for (int i = 0; i < m; i++)                               //Compare all elements from list A with elements from list B
    {
      int k = tmp->get_len ();
      for (int j = 0; j < k; j++)
	{

	  if (tmp->current->data1->data == A->current->data1->data)         //If it equal, we delete this element from tmp list
	    {
	      if (k == 1)
		{
		  delete tmp->head->data1;
		  tmp->head = nullptr;
		  break;
		}
	      tmp->del_to_index (j);
	      break;
	    }

	  else
	    {
	      tmp->current = tmp->current->next;
	    }

	}

      tmp->current = tmp->head;
      A->current = A->current->next;
      if (tmp->check ())                                    //If all elements was deleted, then all of it was in list A
	{
	  std::cout << "Include\n";
	  return 1;
	}
    }
  std::cout << "Not include\n";
  return 0;
}

void
list::get_info_to_index (int index)
{
  current = head;
  int i = 0;
  for (; i < index; i++)
    {
      if (current->next != nullptr)
	{
	  current = current->next;
	}
      else
	{
	  std::cout << "Wrong request\n";
	  break;
	}
    }
  if (i == index)
    {
      get_info ();
    }
}

void
list::view_all ()
{
  current = head;
  while (current != last)
    {
      get_info ();
      current = current->next;
    }
  current = last;
  get_info ();
}
