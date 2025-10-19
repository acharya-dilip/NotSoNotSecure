#include <stdio.h>
#include <gtk/gtk.h>
#include <curl/curl.h>




void checkLogin();
void mainProgram();
void sendMessage();
void updateChat();
size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp);
void closeProgram();

//Global Thinggies
char globalAddText[1024];

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


//Globalised Variables from mainProgram
    GtkWidget *windowMain;
    GtkWidget *entryUserID;
    GtkWidget *textviewChat;
    GtkWidget *entryMessage;
    GtkWidget *windowChat;
void mainProgram() {

    GtkWidget *gridParent;
    GtkWidget *labelUserID;
    GtkWidget *buttonSendMessage;

    //Init of windowMain
    windowMain = gtk_window_new();
    gtk_window_set_default_size(GTK_WINDOW(windowMain),380,400);
    gtk_window_set_title(GTK_WINDOW(windowMain),"NotSoNotSecure");
    gtk_window_present(GTK_WINDOW(windowMain));
    g_signal_connect(windowMain,"destroy",G_CALLBACK(closeProgram),NULL);

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
    //Margins & Paddings
    gtk_widget_set_halign(labelUserID,GTK_ALIGN_START);

    //Init of entryUserID
    entryUserID = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParent),entryUserID,1,0,4,1);
    gtk_editable_set_text(GTK_EDITABLE(entryUserID),gtk_editable_get_text(GTK_EDITABLE(entryGmail)));
    //margins & Paddings
    gtk_widget_set_halign(entryUserID,GTK_ALIGN_START);
    gtk_widget_set_size_request(entryUserID,290,-1);
    gtk_widget_set_margin_start(entryUserID,10);

    //Init of textviewChat
    textviewChat = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(textviewChat), GTK_WRAP_WORD_CHAR);
    gtk_text_view_set_editable(GTK_TEXT_VIEW(textviewChat),FALSE);

    //Init of windowChat
    windowChat = gtk_scrolled_window_new();
    gtk_grid_attach(GTK_GRID(gridParent),windowChat,0,1,5,5);
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(windowChat),textviewChat);
    //Margins & paddings
    gtk_widget_set_hexpand(windowChat,FALSE);
    gtk_widget_set_vexpand(windowChat,TRUE);
    gtk_widget_set_size_request(windowChat,340,300);
    gtk_widget_set_margin_top(windowChat,10);
    gtk_widget_set_margin_bottom(windowChat,10);

    //Init of textviewMessage
    entryMessage = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParent),entryMessage,0,10,5,1);
    //Margins & Paddings
    gtk_widget_set_margin_bottom(entryMessage,10);

    //init of buttonSendMessage
    buttonSendMessage = gtk_button_new_with_label("Send");
    gtk_grid_attach(GTK_GRID(gridParent),buttonSendMessage,0,14,5,1);
    g_signal_connect(buttonSendMessage,"clicked",G_CALLBACK(sendMessage),NULL);

}

void closeProgram() {
    gtk_window_destroy(GTK_WINDOW(windowLogin));
}

void sendMessage() {
    CURL *curl=curl_easy_init();
    CURLcode res;
    if (curl) {
        curl_easy_setopt(curl,CURLOPT_URL,"https://script.google.com/macros/s/AKfycbzU5zH4qlf7ZDO7LWeURhVDw2aVFcpqtyQeaVZ1sxlCANcgJLhLtrXhY_00fz4e0jAm/exec");
        char message[1024];
        snprintf(message, sizeof(message), "{\"text\": \"%s$ \\n %s\"}",
                 gtk_editable_get_text(GTK_EDITABLE(entryUserID)),
                 gtk_editable_get_text(GTK_EDITABLE(entryMessage)));
        curl_easy_setopt(curl,CURLOPT_POSTFIELDS,message);
        curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,1L);
        curl_easy_perform(curl);
    }
    if (res==CURLE_OK) {
        gtk_editable_set_text(GTK_EDITABLE(entryMessage),"");
        updateChat();
    }

    curl_easy_cleanup(curl);
}

void updateChat() {
    // GtkTextBuffer *chatroom = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textviewChat));
    // GtkTextIter end;
    // gtk_text_buffer_get_end_iter(chatroom,&end);
    CURL *curl=curl_easy_init();
    gchar *temp;
    if (curl) {
        curl_easy_setopt(curl,CURLOPT_URL,"https://script.google.com/macros/s/AKfycbzU5zH4qlf7ZDO7LWeURhVDw2aVFcpqtyQeaVZ1sxlCANcgJLhLtrXhY_00fz4e0jAm/exec");
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_callback);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,temp);
    }

}

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t total = size * nmemb;
    strncat((char *)userp, (char *)contents, total);
    return total;
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