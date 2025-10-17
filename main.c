#include <stdio.h>
#include <gtk/gtk.h>
#include <curl/curl.h>






static void activate(GtkApplication *app,gpointer user_data) {
    GtkWidget *windowLogin;
    GtkWidget *entryGmail;
    GtkWidget *entryPassword;
    GtkWidget *labelGmail;
    GtkWidget *labelPassword;
    GtkWidget *buttonLogin;

    windowLogin = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(windowLogin),"Login");
    gtk_window_set_default_size(GTK_WINDOW(windowLogin),300,150);
    gtk_window_present(GTK_WINDOW(windowLogin));


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