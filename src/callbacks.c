#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "string.h"
#include "stdio.h"

char x[1000];
int i = 0;
extern GtkWidget *Display;
GtkWidget *t1;

int check(char);


void
on_Delete_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button), "entry1");
	i--;
	x[i] = '\0';
	gtk_entry_set_text(t1,x);
}


void
on_Dot_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button), "entry1");
	x[i]='.';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);
}


void
on_One_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button), "entry1");
	x[i]='1';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);
}


void
on_Two_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button), "entry1");
	x[i]='2';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);
}


void
on_Three_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button), "entry1");
	x[i]='3';
	i++;
	gtk_entry_set_text(t1,x);
}


void
on_Five_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button), "entry1");
	x[i]='5';
	i++;
	gtk_entry_set_text(t1,x);
}


void
on_Six_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button), "entry1");
	x[i]='6';
	i++;
	gtk_entry_set_text(t1,x);
}


void
on_Clear_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button), "entry1");
	i=0;
	x[i]='\0';
	gtk_entry_set_text(t1,x);
}


void
on_Four_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button), "entry1");
	x[i]='4';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);
}


void
on_Seven_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button), "entry1");
	x[i]='7';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);
}


void
on_Eight_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button), "entry1");
	x[i]='8';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);
}


void
on_Nine_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button), "entry1");
	x[i]='9';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);
}


void
on_Plus_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button), "entry1");
	x[i]='+';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);
}


void
on_Zero_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button), "entry1");
	x[i]='0';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);
}


void
on_Result_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
    char opr[20],opd[20];

    char s[20];

    int i,j=-1,k=-1;

    int a,b,c;

    for(i=0;i<strlen(x);i++)

    {

        if(x[i]>=48 && x[i]<=57)

        {

            j++;

            opd[j]=x[i];

        }

        else

        {

            if(k==-1)

            {

                k++;

                opr[k]=x[i];

            }

            else

            {

                a=check(x[i]);

                b=check(opr[k]);

                while(k>=0 && a<=b)

                {

                    j++;

                    opd[j]=opr[k];

                    k--;

                    if(k==-1)

                    break;

                    b=check(opr[k]);

                }

                k++;

                opr[k]=x[i];

            }

        }

    }

    while(k>=0)

    {

        j++;

        opd[j]=opr[k];

        k--;

    }
	
	j++;
	opd[j]='\0';




    int l=-1;

    int m,n,o;

    for(i=0;i<strlen(opd);i++)

    {

        if(opd[i]>=48 && opd[i]<=57)

        {

            l++;

            s[l]=opd[i]-48;

        }

        else

        {

            o=s[l];

            l--;

            n=s[l];

            l--;

            if(opd[i]=='-')

            m=n-o;

            else

            if(opd[i]=='+')

            m=n+o;

            else

            if(opd[i]=='/')

            m=n/o;

            else

            if(opd[i]=='*')

            m=n*o;

            l++;

            s[l]=m;

        }

    }

        t1=lookup_widget(GTK_WIDGET(button),"entry1");
       	i=0;
	memset(x,0,sizeof(x));
	sprintf(x,"%d",s[l]);
        gtk_entry_set_text(t1,x);
}

int check(char m)

{

    switch(m)

    {

        case '+':

        case '-':

        return 5;

        case '/':

        case '*':

        case '%':

        return 6;

    }

}

void
on_Multiply_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button), "entry1");
	x[i]='*';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);
}


void
on_Minus_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button), "entry1");
	x[i]='-';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);
}


void
on_Divide_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button), "entry1");
	x[i]='/';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);
}

