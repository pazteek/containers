#include "map.hpp"
#include <map>
#include <cstdlib>

int main(int argv, char ** argc)
{
  ft::map<int , int> a;
  std::map<int , int> b;
  std::pair<const int, int> e(10, 100);

  if (argv != 2)
  return 0;
    int u = atoi(argc[1]);
    int i;
  srand(time(NULL));
    while (u-- != 0)
    {
      i =  rand()% 100;
              std::cout << "rajout " << i << std::endl;
       a.insert(ft::pair<const int, int>(i, 100));
        a.print_tab();
        std::cout << "FIN" << std::endl;

    }
  return 0;
  a.insert(ft::pair<const int, int>(10, 100));
  a.insert(ft::pair<const int, int>(5, 1000));
  a.insert(ft::pair<const int, int>(20, 1000));
      a.insert(ft::pair<const int, int>(3, 1000));

      a.insert(ft::pair<const int, int>(7, 1000));

    a.insert(ft::pair<const int, int>(25, 1000));

      a.insert(ft::pair<const int, int>(30, 1000));


      a.insert(ft::pair<const int, int>(35, 1000));
                      
           a.insert(ft::pair<const int, int>(40, 1000));
          
                a.insert(ft::pair<const int, int>(45, 1000));
                std::cout << "rajout 45" << std::endl;
                     a.print_tab();
                     std::cout << "FIN" << std::endl;
                     a.insert(ft::pair<const int, int>(50, 1000));
                      std::cout << "rajout 50" << std::endl;
                     a.print_tab();
                     std::cout << "FIN" << std::endl;
                     return 0;
                          a.insert(ft::pair<const int, int>(55, 1000));
                               a.insert(ft::pair<const int, int>(60, 1000));
                                    a.insert(ft::pair<const int, int>(65, 1000));
                                          a.insert(ft::pair<const int, int>(35, 1000));
           a.insert(ft::pair<const int, int>(36, 1000));
                a.insert(ft::pair<const int, int>(-5, 1000));
                     a.insert(ft::pair<const int, int>(100, 1000));
                          a.insert(ft::pair<const int, int>(10001, 1000));
                               a.insert(ft::pair<const int, int>(4545, 1000));
                                    a.insert(ft::pair<const int, int>(44, 1000));
                                               a.insert(ft::pair<const int, int>(96, 1000));
                a.insert(ft::pair<const int, int>(-614, 1000));
                     a.insert(ft::pair<const int, int>(49, 1000));
                          a.insert(ft::pair<const int, int>(55, 1000));
                               a.insert(ft::pair<const int, int>(64, 1000));
                                    a.insert(ft::pair<const int, int>(84, 1000));
                                               a.insert(ft::pair<const int, int>(4515, 1000));
                a.insert(ft::pair<const int, int>(415, 1000));
                     a.insert(ft::pair<const int, int>(45415, 1000));
                          a.insert(ft::pair<const int, int>(4544, 1000));
                               a.insert(ft::pair<const int, int>(4515, 1000));
                                    a.insert(ft::pair<const int, int>(4544414, 1000));
                                               a.insert(ft::pair<const int, int>(494, 1000));
                a.insert(ft::pair<const int, int>(-15, 1000));
                     a.insert(ft::pair<const int, int>(11, 1000));
                          a.insert(ft::pair<const int, int>(-154, 1000));
                               a.insert(ft::pair<const int, int>(45584, 1000));
                                    a.insert(ft::pair<const int, int>(7445, 1000));
                                               a.insert(ft::pair<const int, int>(-10521, 1000));
                a.insert(ft::pair<const int, int>(11111, 1000));
                     a.insert(ft::pair<const int, int>(120, 1000));
                          a.insert(ft::pair<const int, int>(-3, 1000));
                               a.insert(ft::pair<const int, int>(15484, 1000));
                                    a.insert(ft::pair<const int, int>(34, 1000));
                                               a.insert(ft::pair<const int, int>(23, 1000));
                a.insert(ft::pair<const int, int>(4511, 1000));
                     a.insert(ft::pair<const int, int>(81, 1000));
                          a.insert(ft::pair<const int, int>(32, 1000));
                               a.insert(ft::pair<const int, int>(154847, 1000));
                                    a.insert(ft::pair<const int, int>(-2154, 1000));
                                               a.insert(ft::pair<const int, int>(128574, 1000));
                a.insert(ft::pair<const int, int>(474, 1000));
                     a.insert(ft::pair<const int, int>(-1514, 1000));
                          a.insert(ft::pair<const int, int>(154, 1000));
                               a.insert(ft::pair<const int, int>(-4544, 1000));
                                    a.insert(ft::pair<const int, int>(154854, 1000));

                          
              //    std::map<int , int>::iterator v(b.begin());
                //     std::cout << "first = " <<  v->first << " seconde = " << std::endl; 
          std::cout << "deb" << std::endl;
          a.print_tab();
          std::cout << "FIN" << std::endl;
 // b.insert(e);
/*

 
  if (b.begin() == b.end())
    ;
    do
    {
      std::cout << "first = " <<  v->first << " seconde = " << std::endl; 
    } 
    while (++v != b.end());

     std::pair<const int, int> aaa(*v);


    std::cout << aaa.first << std::endl;
  
          */
 // v++;
 // u++;
 // u = e;




  return (0);
}


/*
int main()
{
    int n[] = {10,20,30,40,50,60,70,80,90,100,110};
       ft::vector<int> l(n , n+10);
        std::vector<int> a(n , n+10);
        std::vector<int>::iterator ls(a.begin());
       std::cout << ls.base() << std::endl;
        l.insert(l.begin(), 4 , 3);
      //  a.insert(0, n+1, n+5);
       // a.insert(a.begin(), n+1, n+5);
     //   std::cout << l[0] << "  " << l[9] << std::endl;
       // std::cout << a[0] << "  " << a[9] << std::endl;
             //int n[] = {10,20,30,40,50,60,70,80,90,100,110};
   //   ft::vector<int> l(n , n+10);
      ft::vector<int>  d(10, 12);
      std::vector<int>  a(10, 12);
            ft::vector<int>  dd(10, 12);
      std::vector<int>  dd(10, 12);
  //   d.insert(d.begin(), 112);
  //   a.insert(a.begin(), 112);
     d.insert(d.begin(), 5, 100);
     a.insert(a.begin(), 5 ,  100);
    std::vector<int>::iterator t = a.begin();
      ft::vector<int>::iterator e = d.begin();
     d.insert(e+15, 4, -6);
     a.insert(t+15, 4 ,  -6);

//     std::cout << "t "<<*t << std::endl;
  //   std::cout << "e "<< *e << std::endl;

      a.erase(t + 2);
      d.erase(e + 2);
      d.erase(e+3, e+5);
      a.erase(t+3, t+5);
     std::cout << std::endl;
        for (size_t i = 0; i < d.size(); i++)
        {
            std::cout << "d "<< i << "  " << d[i] << std::endl;
            std::cout << "a "<<i << "  " << a[i] << std::endl << std::endl;
        }
    std::cout <<  "d " << d.capacity() << " " << d.size() << std::endl;
    std::cout <<  "a " << a.capacity() << " " << a.size() << std::endl;
    dd.swap(d);
    aa.swap(a);
    return (0);
    d = l;




    d.reserve(23);

    for (size_t i = 0; i < d.size();  i++)
    {
       std::cout << "d["  << i << "] = " << d[i] << " ";
    }
    std::cout << std::endl;
    //    l.push_back(23);
   // for (size_t i = 0; i < l.size();  i++)
   // {
    //    std::cout << "l["  << i << "] = " << l[i] << " ";
    //}
  

    return 0;
}
*/