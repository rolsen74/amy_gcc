/* A custom implementation of various env functions
 *
 * This is necessary as no official clib supports unsetenv()
 * but setenv().
 */
#define __USE_INLINE__

#include <proto/dos.h>
#include <proto/exec.h>

#include <string.h>


#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

int
setenv (const char *name, const char *value, int replace)
{
   if (!replace)
   {
       if (FindVar(name, GVF_LOCAL_ONLY))
       {
           return 0;
       }
   }

   return !SetVar(name, value, -1, GVF_LOCAL_ONLY);
}

void
unsetenv (const char *name)
{
   DeleteVar(name, GVF_LOCAL_ONLY);
}

void
putenv (char *str)
{
   int i;

   if (str[0] == '=')
   {
       return;
   }

   for (i=0; str[i]; i++)
   {
       if (str[i] == '=')
       {
           char *name = (char*)AllocVec(i + 1, MEMF_ANY);
           if (name)
           {
               strncpy(name, str, i);
               name[i] = 0;

               setenv(name, &str[i] + 1, 1);
               FreeVec(name);
               return;
           }
       }
   }
}

char *
getenv (const char *name)
{
   struct LocalVar *lvar;

   if (!(lvar = FindVar(name, GVF_LOCAL_ONLY)))
   {
       return NULL;
   }
   return lvar->lv_Value;
}
