#include "apue.h"
#include <pwd.h>
#include <grp.h>
#include <shadow.h>

struct passwd *mygetpwname(const char *name)
{
    struct passwd *pptr;

    setpwent();

    while ((pptr = getpwent()) != NULL)
    {
        if (strcmp(pptr->pw_name, name) == 0)
        {
            break;
        }
    }

    endpwent();

    return pptr;
}

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <name>\n",argv[0]);
        exit(1);
    }

    struct passwd *ptr;
    struct spwd *sptr;
    struct group *gptr;
    int i=0;

    ptr=mygetpwname(argv[1]);

    if (ptr == NULL)
    {
        printf("User unfound: %s\n", argv[1]);
    }
    else
    {
        //printf("Name: %s\nPasswd: %s\nUID: %d\nGID: %d\nGECOS: %s\nDIR: %s\nSHELL: %s\n", 
        //    ptr->pw_name, ptr->pw_passwd, ptr->pw_uid, ptr->pw_gid, ptr->pw_gecos, ptr->pw_dir, ptr->pw_shell);
        printf("PASSWD:\n%s:%s:%d:%d:%s:%s:%s\n", ptr->pw_name, ptr->pw_passwd, ptr->pw_uid, ptr->pw_gid, ptr->pw_gecos, ptr->pw_dir, ptr->pw_shell);

        if ((sptr=getspnam(argv[1])) != NULL)
        {
            printf("SHADOW:\n%s:%s\n",/*:%d:%d:%s:%s:%s*/ sptr->sp_namp, sptr->sp_pwdp);//, ptr->pw_uid, ptr->pw_gid, ptr->pw_gecos, ptr->pw_dir, ptr->pw_shell);
        }

        if ((gptr=getgrgid(ptr->pw_gid))!= NULL)
        {
            printf("Group:\n%s:%s:%d:", gptr->gr_name, gptr->gr_passwd, gptr->gr_gid);

            while (gptr->gr_mem[i] != NULL)
            {
                printf("%s,", gptr->gr_mem[i]);
                i++;
            }
            printf("\n");
        }
    }

    return 0;
}
