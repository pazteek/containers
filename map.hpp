# ifndef MAP_HPP
#define MAP_HPP

#include "iterator_map.hpp"
#include <memory>
#include <stdexcept>
#include <functional>
#include "is_integral.hpp"
#include "enable_if.hpp"
#include "lexicograpfical_copare.hpp"
#include "node.hpp"
#include "pair.hpp"
#include <unistd.h>


#define RESET   "\033[0m"
#define BLACKCOLOR   "\033[30m"      /* Black */
#define REDCOL    "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"       /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"


namespace ft {


template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
class map {
public:
// types:
typedef Key key_type;
typedef T mapped_type;
typedef ft::pair<const Key, T> value_type;
typedef Compare key_compare;
typedef Allocator allocator_type;
typedef typename Allocator::reference reference;
typedef typename Allocator::const_reference const_reference;

        typedef std::size_t size_type;
        typedef ft::Iterator< ft::node<value_type> > iterator;
        typedef ft::Iterator< const ft::node<value_type> > const_iterator;
        typedef std::ptrdiff_t difference_type;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef  ft::reverse_iterator<const_iterator> const_reverse_iterator;

//typedef implementation defined iterator;  See 23.1
//typedef implementation defined const_iterator;  See 23.1
//typedef implementation defined size_type;  See 23.1
//typedef implementation defined difference_type;  See 23.1
typedef typename Allocator::pointer pointer;
typedef typename Allocator::const_pointer const_pointer;
//typedef std::reverse_iterator<iterator> reverse_iterator;
//typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
class value_compare
: public std::binary_function<value_type,value_type,bool> {
friend class map;
protected:
Compare comp;

value_compare(Compare c) : comp(c)  {}
public:
bool operator()(const value_type& x, const value_type& y) const {
return comp(x.first, y.first);
}
};
// 23.3.1.1 construct/copy/destroy:
explicit map(const Compare& comp = Compare(),
const Allocator& = Allocator())
{
   _node = NULL;
    (void) comp;
}
template <class InputIterator>
map(InputIterator first, InputIterator last,
const Compare& comp = Compare(), const Allocator& = Allocator());
map(const map<Key,T,Compare,Allocator>& x) : _node(NULL), _ptrdeb(NULL), _ptrfin(NULL)
{
    std::allocator<ft::node<value_type> > _a;
    _ptrfin = _a.allocate(1);
    // _a.construct(_ptrfin ,ft::node<value_type>());
    (void)x;
}
~map()
{   
}
map<Key,T,Compare,Allocator>&
operator=(const map<Key,T,Compare,Allocator>& x);
// iterators:
iterator begin()
{
  /*  node<value_type> *tmp = _node;

    while (tmp->left != NULL)
        tmp = tmp->left;*/
    return (iterator(_ptrdeb));
}
const_iterator begin() const;
iterator end()
{
    return (iterator(_ptrfin));
}
const_iterator end() const;
reverse_iterator rbegin();
const_reverse_iterator rbegin() const;
reverse_iterator rend();
const_reverse_iterator rend() const;
// capacity:
bool empty() const;
size_type size() const;
size_type max_size() const;
// 23.3.1.2 element access:
T& operator[](const key_type& x)
{
    node<value_type> *tmp = _node;

    while ( (tmp->left != NULL || tmp->rigth != NULL) && tmp->type.first != x)
    {
        if (tmp->type.first > x)
            tmp = tmp->left;
        else
            tmp = tmp->rigth;
    }

    if (tmp->type.first == x)
        return tmp->type.seconde;
    T *a = new T();
    return *a;
}
// modifiers:
    bool st_tab(ft::node<value_type> **tmp, int n)
    {
        int i = 0;
        while (i != n && (tmp[i] == NULL || tmp[i] == _ptrfin))
            i++;
    return !(i == n);
    }

    void print_tmp(ft::node<value_type> **tmp, int n)
    {
        int i = 0;
        while (i != n)
        {
            if (tmp[i] == NULL || tmp[i] == _ptrfin)
            {
                std::cout << "|ED|";
            }
            else
            {
                if (tmp[i]->color == ROUGE)
                    std::cout << REDCOL << "|"<< tmp[i]->type.first << "|" << RESET;
                else
                    std::cout << "|"<< tmp[i]->type.first <<"|";
            }
            if ( 1 == i%2)
            std::cout << " ";
            i++;
        }
        std::cout << std::endl;
    }

    ft::node<value_type> **init_tmp( ft::node<value_type> **tmp, int n)
    {
        int i = 0;
           ft::node<value_type>  **tmp2 = new node<value_type>*[n * 2];
         while (i != n)
        {

 
            if (tmp[i] == NULL ||tmp[i] == _ptrfin)
            {
                tmp2[i * 2] = NULL;
                tmp2[i * 2 + 1] = NULL;
            }
            else
            {
                    tmp2[i*2] = tmp[i]->left;
                    tmp2[i*2 + 1] = tmp[i]->rigth;
            }
            i++;
        }
            return tmp2;
    }

    void print_tab()
    {
        ft::node<value_type>    **tmp = new ft::node<value_type>*[1];
        //malloc( sizeof(ft::node<value_type>*) * 1);
        int                     n = 1;
        ft::node<value_type>  **tmp2 = NULL;
        int i = 0;

        tmp = &_node;
        while (st_tab(tmp, n))
        {
            print_tmp(tmp, n);
            tmp2 = init_tmp( tmp, n);
           // usleep(2500);
         //   delete [] *tmp;
            n *= 2;
            tmp = tmp2;
            i++;
     //   std::cout << "NOMBRE DE LIGNE " << i << std::endl;
        }
    //    std::cout << std::endl <<"NOMBRE DE LIGNE " << i << std::endl;
    }

    void color(ft::node<value_type> *GP, ft::node<value_type> *P)
    {
        GP->parents->color = NOIR;
        if (P->left != NULL)
            P->left->color = ROUGE;
        if (P->rigth != NULL)
            P->rigth->color = ROUGE;

    }
     void color2(ft::node<value_type> *GP)
     {
          GP->color = ROUGE;
        if (GP->left != NULL)
            GP->left->color = NOIR;
        if (GP->rigth != NULL)
            GP->rigth->color = NOIR;

     }

   void rotate(ft::node<value_type> *GPP, ft::node<value_type> *GP, ft::node<value_type> *P, ft::node<value_type> *F, int i)
   {
                if (GPP != NULL)
                {
                    if (GPP->left == GP)
                        GPP->left = P;
                    else
                        GPP->rigth = P;
                }
                else
                    _node = P;
        P->parents = GPP;
        if (GP->left == P)
            GP->left = F;
        else
            GP->rigth = F;
        if (P->left == F && i != 0)
            P->left = GP;
        else
            P->rigth = GP;
       P->parents = GP->parents;
       GP->parents = P;
        if (F != NULL)
            F->parents = GP;
       if (i == 1)
            color(GP, P);
   }
void equilibre(ft::node<value_type> *tmp)
{
    if (tmp == NULL || tmp->parents == NULL || tmp->parents->parents == NULL)
    {
         _node->color = NOIR;
        return;
    }
    if (tmp->color == NOIR)
    {
        equilibre(tmp->parents);
       return ;
    }
    int col = NOIR;
    if ((tmp->parents->parents->left != NULL && tmp->parents->parents->left->color == ROUGE ) &&  (tmp->parents->parents->rigth != NULL && tmp->parents->parents->rigth != _ptrfin && tmp->parents->parents->rigth->color == ROUGE))
        col = ROUGE;
    if (col == ROUGE)
    {   
     //   std::cout << "cas 0" << std::endl;
        color2(tmp->parents->parents);
         equilibre(tmp->parents->parents);
         _node->color = NOIR;
         return;
    }
    else if (tmp->parents->color == ROUGE)
    {
        if (tmp->parents->parents->left == tmp->parents)
        {
            if (tmp->parents->rigth == tmp)
            {
                //std::cout << "cas 1" << std::endl;
                rotate(tmp->parents->parents ,tmp->parents, tmp, tmp->left,-1);
                rotate(tmp->parents->parents ,tmp->parents, tmp, tmp->rigth,1);
                equilibre(tmp->parents);
            }
            else
            {
               //   std::cout << "cas 2" << std::endl;
                rotate(tmp->parents->parents->parents ,tmp->parents->parents, tmp->parents, tmp->parents->rigth, 1);
                equilibre(tmp->parents->parents);
            }
        }
        else
        {
               if (tmp->parents->left == tmp)
               {
              //     std::cout << "cas 3" << std::endl;
                rotate(tmp->parents->parents ,tmp->parents, tmp, tmp->rigth, 0);
                rotate(tmp->parents->parents ,tmp->parents, tmp, tmp->left,1);
                return;
                //equilibre(tmp->parents);
               }
               else
               {
               //    std::cout << "cas 4 " << tmp->type.first << std::endl;

                rotate(tmp->parents->parents->parents, tmp->parents->parents, tmp->parents,  tmp->parents->left, 1);
                return;
                //equilibre(tmp->parents->parents);
               }
        }   
    }
  //  equilibre(tmp->parents);
}

ft::node<value_type>* alloc_insert(const value_type& x, ft::node<value_type> *node, ft::node<value_type> *node2)
{
    std::allocator<ft::node<value_type> > _a;
    if (node == NULL)
    {
     //   std::cout << "insert" << std::endl;
         node = _a.allocate(1);
        _a.construct(node ,ft::node<value_type>(x));
        node->parents = node2;
    }
    return (node);
}

ft::pair<iterator, bool> insert(const value_type& x)
{
        std::allocator<ft::node<value_type> > _a;
    if (_node == NULL)
    {
     //    std::cout << "racine mise" << std::endl;
        _node = alloc_insert(x, _node, NULL);
        _ptrdeb = _node;
        _node->rigth = _ptrfin;  
        _node->color = NOIR;
            return ft::pair<iterator, bool>();
    }
    else
    {
        node<value_type> *tmp = _node;
        while (tmp != NULL)
        {
            if (tmp->type.first >= x.first)
            {;
                    if (tmp->left == NULL)
                    {
                    tmp->left = _a.allocate(1);
                    _a.construct(tmp->left ,ft::node<value_type>(x));
                    tmp->left->parents = tmp;
                    tmp = tmp->left;
                    if (tmp->parents == _ptrdeb)
                        _ptrdeb = tmp;
                    break;
                    }
                    tmp = tmp->left;
                /*
                tmp = alloc_insert(x, tmp->left, tmp);
                std::cout << "left enfant" << std::endl;
                */
            }
            else
            {
 
                    if (tmp->rigth == NULL || tmp->rigth == _ptrfin)
                    {
   
                        if (tmp->rigth == _ptrfin)
                        {
          
                            tmp->rigth = _a.allocate(1);
                             _a.construct(tmp->rigth ,ft::node<value_type>(x));

                            tmp->rigth->rigth = _ptrfin;
          
                         //   _ptrfin->parents = tmp->rigth;
                        }
                        else
                        {
                            tmp->rigth = _a.allocate(1);
                            _a.construct(tmp->rigth ,ft::node<value_type>(x));
                        }
                        tmp->rigth->parents = tmp;
                        tmp = tmp->rigth;
                        break;
                    }
                    tmp = tmp->rigth;
            }
        }
  
         if (tmp != NULL)
         {
           //  std::cout << "AVANT EQUI" << std::endl;
             //   this->print_tab();
                ///        std::cout << "AVANT EQUI" << std::endl;
             if ( tmp->parents->color == ROUGE)
             {
                
                    equilibre(tmp);
              }  //     std::cout << "APRES EQUI" << std::endl;

                    //     std::cout << "APRES EQUI" << std::endl;
         }
    }
    return ft::pair<iterator, bool>();
}
iterator insert(iterator position, const value_type& x);

template <class InputIterator>
void insert(InputIterator first, InputIterator last);

void erase(iterator position);



void rotatedelet(node<value_type> *tmp2, node<value_type> *frere)
{
    if (frere->parents->left == frere)
    {
        if (frere->left != NULL && frere->left->color == ROUGE)
        {
            rotate(tmp2->parents ,tmp2, frere, frere->rigth, 0);
            return;
        }
        else
        {
            //std::cout << "cas 1 " << frere->rigth->rigth << " " << tmp2 << "  " << frere->rigth->left<< std::endl;
                rotate(tmp2 ,frere, frere->rigth,  frere->rigth->rigth, -1);
             //this->print_tab();
             //std::cout << "cas 1 " <<  tmp2->type.first << " " << frere->parents->rigth << std::endl;
                rotate(tmp2->parents , tmp2, frere->parents,  frere->parents->rigth, 0);
                return;
        }

    }
    else
    {

        if (frere->rigth != _ptrfin && frere->rigth != NULL && frere->rigth->color == ROUGE)
        {
              rotate(tmp2->parents ,tmp2, frere, frere->left, 0);
            return;
        }
        else
        {
                
                rotate(tmp2 ,frere, frere->left,  frere->left->left,-1);
                      rotate(tmp2->parents , tmp2, frere->parents,  frere->parents->left, 0);
                return;
        }

    }
}

size_type erase(const key_type& x)
{
   node<value_type> *tmp = _node;
    std::allocator<ft::node<value_type> > _a;
    int u;
    int v;
    while ( (tmp->left != NULL || tmp->rigth != NULL) && tmp->type.first != x)
    {
        if (tmp->type.first > x)
            tmp = tmp->left;
        else
            tmp = tmp->rigth;
    }
     node<value_type> *tmp2 = tmp->parents;
    node<value_type> *tmp3 = tmp;
     v = tmp->color;
    if (tmp->rigth == NULL && tmp->left == NULL)
    {
        std::cout << "RACCINE CAS" << std::endl;
        if (tmp2->left == tmp)
            tmp2->left = NULL;
        else
            tmp2->rigth = NULL;
       
        u = NOIR;
        _a.destroy(tmp);
        tmp3 = NULL;
    }
    else if ( tmp->left == NULL || tmp->rigth == NULL )
    {
                std::cout << "CAS 1 fils" << std::endl;
        if (tmp->left == NULL)
        {  
            tmp->rigth->parents = tmp2;
             tmp3 = tmp->rigth;
            u = tmp3->color;
             if (tmp2->left == tmp)
                tmp2->left = tmp->rigth;
            else
                tmp2->rigth = tmp->rigth;
            _a.destroy(tmp);
        }
        else
        {
                           
            tmp->left->parents = tmp2;
            tmp3 = tmp->left;
            u = tmp3->color;
             if (tmp2->left == tmp)
                tmp2->left = tmp->left;             
                else
                tmp2->rigth = tmp->left;
            _a.destroy(tmp);
        }
    }
    else
    {        std::cout << "CAS 2 fils" << std::endl;
            tmp3->parents = tmp2;

           
            tmp3 = ++(*tmp3);
            std::cout << "CAS 2 fils" << tmp3->type.first << std::endl;
             if (tmp2)
            {
             if (tmp2->left == tmp)
                tmp2->left = tmp3;
             else
                tmp2->rigth = tmp3;
            }   
              std::cout << "CAS 2 fils" << tmp3->type.first << std::endl;
           
            u = tmp3->color;
            if (tmp->left != tmp3)
            tmp3->left = tmp->left;
            else 
            tmp3->left = NULL;
             if (tmp->rigth != tmp3)
            tmp3->rigth = tmp->rigth;
             else 
            tmp3->rigth = NULL;

            if (tmp3->parents->left == tmp3)
                tmp3->parents->left = NULL;
            else
                tmp3->parents->rigth = NULL;
            std::cout << "CAS 2 fils" << tmp3->type.first << std::endl;
           
            _a.destroy(tmp);
            tmp = NULL;
          //  this->print_tab();
    }
    node<value_type> *frere;
 //std::cout << "ABBBAAAAA" << tmp2 << std::endl;
    if (tmp2)
    {
        if (tmp2->left == tmp3)
        frere = tmp2->rigth;
        else
        frere = tmp2->left;
    }
    else
    frere = NULL;
   //std::cout << "ABBBAAAAA" << std::endl;
    if (u == ROUGE || v == ROUGE)
    {
        if (tmp3)
            tmp3->color = NOIR;
    //     std::cout << "ABBBAAAAA" << tmp3->type.first << " " << tmp2->type.first << std::endl;
        return 1;
    }
 //   std::cout << "ABBBAAAAA " << frere->type.first << " " << tmp2 << std::endl;
    if (frere != NULL && frere != _ptrfin && ((frere->left != NULL  && frere->left->color == ROUGE ) || (frere->rigth != NULL && frere->rigth != _ptrfin && frere->rigth->color == ROUGE)))
    {
        std::cout << "frere et fils" << std::endl;
            this->rotatedelet(tmp2, frere);
            _node->color = NOIR;
            return 1;
    }
    if (frere != NULL && frere != _ptrfin)
    {
        frere->color = ROUGE;
        _node->color = NOIR;
        return 1;
    }
    if (frere != NULL && frere != _ptrfin && frere->color == ROUGE)
    {
        if (frere->parents->left == frere)    
                rotate(tmp2->parents, tmp2, frere,  frere->rigth, 1);
        else   
                rotate(tmp2->parents, tmp2, frere,  frere->left, 1);
        _node->color = NOIR;
        return 1;
    }
    if (frere != NULL && frere->color == NOIR)
    {
        frere->color= ROUGE;
    }
    if (frere == NULL || frere->left->color == NOIR ||  frere->rigth->color == NOIR)
    {
        while (tmp3 && tmp3->color == NOIR)
        {


        }
    }
    _node->color = NOIR;
    return (1);
}
void erase(iterator first, iterator last);
void swap(map<Key,T,Compare,Allocator>&);
void clear();
// observers:
key_compare key_comp() const;
value_compare value_comp() const;


iterator find(const key_type& x);
const_iterator find(const key_type& x) const;
size_type count(const key_type& x) const;
iterator lower_bound(const key_type& x);
const_iterator lower_bound(const key_type& x) const;
iterator upper_bound(const key_type& x);
const_iterator upper_bound(const key_type& x) const;
ft::pair<iterator,iterator>
equal_range(const key_type& x);
ft::pair<const_iterator,const_iterator>
equal_range(const key_type& x) const;
    private:
        node<value_type>    *_node;
        allocator_type      _alloc;
        node<value_type>    *_ptrdeb;
        node<value_type>    *_ptrfin;
};

template <class Key, class T, class Compare, class Allocator>bool operator==(const map<Key,T,Compare,Allocator>& x,const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>bool operator< (const map<Key,T,Compare,Allocator>& x,const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>bool operator!=(const map<Key,T,Compare,Allocator>& x,const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>bool operator> (const map<Key,T,Compare,Allocator>& x,const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>bool operator>=(const map<Key,T,Compare,Allocator>& x,const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>bool operator<=(const map<Key,T,Compare,Allocator>& x,const map<Key,T,Compare,Allocator>& y);
//specialized algorithms:
template <class Key, class T, class Compare, class Allocator>void swap(map<Key,T,Compare,Allocator>& x,map<Key,T,Compare,Allocator>& y);

}
# endif
