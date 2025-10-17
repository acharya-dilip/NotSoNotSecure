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
    //Margins & Paddigns
    gtk_widget_set_halign(gridParentLogin,GTK_ALIGN_CENTER);
    gtk_widget_set_valign(gridParentLogin,GTK_ALIGN_CENTER);
    gtk_widget_set_margin_start(gridParentLogin,10);
    gtk_widget_set_margin_end(gridParentLogin,10);
    gtk_widget_set_margin_top(gridParentLogin,10);
    gtk_widget_set_margin_bottom(gridParentLogin,10);



    //Initalisation of labelGmail
    labelGmail = gtk_label_new("Gmail:");
    gtk_grid_attach(GTK_GRID(gridParentLogin),labelGmail,0,0,1,1);
    //Margins & paddings
    gtk_widget_set_halign(labelGmail,GTK_ALIGN_START);
    gtk_widget_set_margin_end(labelGmail,10);



    //Initialisation of entryGmail
    entryGmail = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParentLogin),entryGmail,1,0,1,1);
    //Margins & Paddigns
    gtk_widget_set_size_request(entryGmail,240,-1);

    //Initialisation of labelPassword
    labelPassword = gtk_label_new("Pass:");
    gtk_grid_attach(GTK_GRID(gridParentLogin),labelPassword,0,1,1,1);

    //Initalisation of entryPassword
    entryPassword = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParentLogin),entryPassword,1,1,1,1);

    //Initialisation of buttonLogin
    buttonLogin = gtk_button_new_with_label("Login");
    gtk_grid_attach(GTK_GRID(gridParentLogin),buttonLogin,1,2,1,1);




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