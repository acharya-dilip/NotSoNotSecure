#include <stdio.h>
#include <gtk/gtk.h>
#include <curl/curl.h>






static void activate(GtkApplication *app,gpointer user_data) {
    GtkWidget *windowLogin;
    GtkWidget *gridParentLogin;
    GtkWidget *entryGmail;
    GtkWidget *entryPassword;
    GtkWidget *labelGmail;
    GtkWidget *labelPassword;
    GtkWidget *buttonLogin;

    //Initialisation of windowLogin
    windowLogin = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(windowLogin),"Login");
    gtk_window_set_default_size(GTK_WINDOW(windowLogin),300,150);
    gtk_window_present(GTK_WINDOW(windowLogin));

    //Initalisation of gridParentLogin
    gridParentLogin = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(windowLogin),gridParentLogin);

    //Initalisation of labelGmail
    labelGmail = gtk_label_new("Gmail:");
    gtk_grid_attach(GTK_GRID(gridParentLogin),labelGmail,0,0,1,1);

    //Initialisation of entryGmail
    entryGmail = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParentLogin),entryGmail,1,0,1,1);




}




int main(int argc, char **argv){
    GtkApplication *app;
    int status;
    app= gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);


    return status;
}