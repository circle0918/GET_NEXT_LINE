#include "get_next_line.h"
 
 int  ft_strchr(char *s, char c)
 {   
     while(s && *s)
     {   
         if (*s == c)
             return (1);
         s++;
     }
     return (0);
 }
 
 size_t ft_strlen(char *s)
 {   
     size_t i;
     
     i = 0;
     while(s[i])
         i++;
     return(i);
 }

