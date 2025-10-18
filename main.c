#include <stdio.h>
#include <gtk/gtk.h>
#include <curl/curl.h>




void checkLogin();
void mainProgram();

//Global Variables from windowLogin
    GtkWidget *windowLogin;
    GtkWidget *entryGmail;
    GtkWidget *entryPassword;
static void activate(GtkApplication *app,gpointer user_data) {

    GtkWidget *gridParentLogin;

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
    g_signal_connect(buttonLogin,"clicked",G_CALLBACK(checkLogin),NULL);

}


void checkLogin() {
    CURL *curl = curl_easy_init();
    CURLcode result;
    if (curl) {
        //Initialisation of the gmail auth segment
        curl_easy_setopt(curl,CURLOPT_URL,"smtp://smtp.gmail.com:587");
        curl_easy_setopt(curl,CURLOPT_USE_SSL,(long)CURLUSESSL_ALL);
        curl_easy_setopt(curl,CURLOPT_USERNAME,gtk_editable_get_text(GTK_EDITABLE(entryGmail)));
        curl_easy_setopt(curl,CURLOPT_PASSWORD,gtk_editable_get_text(GTK_EDITABLE(entryPassword)));

        result = curl_easy_perform(curl);
        if (result == CURLE_OK) {
            //hides the windowLogin window
            gtk_widget_set_visible(windowLogin,FALSE);
            //Executes the main Program
            mainProgram();
        }
        mainProgram();
        curl_easy_cleanup(curl);
    }
}


void mainProgram() {

    GtkWidget *windowMain;
    GtkWidget *gridParent;
    GtkWidget *labelUserID;
    GtkWidget *entryUserID;
    GtkWidget *textviewChat;
    GtkWidget *entryMessage;
    GtkWidget *buttonSendMessage;

    //Init of windowMain
    windowMain = gtk_window_new();
    gtk_window_set_default_size(GTK_WINDOW(windowMain),400,400);
    gtk_window_set_title(GTK_WINDOW(windowMain),"NotSoNotSecure");
    gtk_window_present(GTK_WINDOW(windowMain));

    //Init of gridParent
    gridParent = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(windowMain),gridParent);
    //Margins & Paddings
    gtk_widget_set_halign(gridParent,GTK_ALIGN_CENTER);
    gtk_widget_set_valign(gridParent,GTK_ALIGN_CENTER);
    gtk_widget_set_margin_start(gridParent,15);
    gtk_widget_set_margin_end(gridParent,15);
    gtk_widget_set_margin_top(gridParent,15);
    gtk_widget_set_margin_bottom(gridParent,15);

    //init of labelUserID
    labelUserID = gtk_label_new("UserID:");
    gtk_grid_attach(GTK_GRID(gridParent),labelUserID,0,0,1,1);

    //Init of entryUserID
    entryUserID = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParent),entryUserID,1,0,4,1);

    //Init of textviewChat
    textviewChat = gtk_text_view_new();
    gtk_grid_attach(GTK_GRID(gridParent),textviewChat,0,1,5,8);
    gtk_text_view_set_editable(GTK_TEXT_VIEW(textviewChat),FALSE);
    //Margins & paddings
    gtk_widget_set_size_request(textviewChat,240,300);
    gtk_widget_set_margin_top(textviewChat,10);
    gtk_widget_set_margin_bottom(textviewChat,10);

    //Init of textviewMessage
    entryMessage = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParent),entryMessage,0,10,5,1);
    //Margins & Paddings
    gtk_widget_set_margin_bottom(entryMessage,10);

    //init of buttonSendMessage
    buttonSendMessage = gtk_button_new_with_label("Send");
    gtk_grid_attach(GTK_GRID(gridParent),buttonSendMessage,0,14,5,1);

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