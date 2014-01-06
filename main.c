#include <gtk/gtk.h>

void about(GtkWidget *wid, GtkWidget *win)
{
    GtkWidget *dialog = NULL;
    dialog = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "TEST!");
    gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
    gtk_dialog_run (GTK_DIALOG (dialog));
    gtk_widget_destroy (dialog);
}

void simplemenu(GtkWidget *wid, GtkWidget *win_)
{
	GtkWidget *win = NULL;
	GtkWidget *vbox = NULL;
	GtkWidget *button = NULL;
      /* Create the main window */
    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width (GTK_CONTAINER (win), 60);
    gtk_window_set_title (GTK_WINDOW (win), "Gtk3 TEST");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    //  gtk_widget_realize (win);//WHAT IS THIS FOR!?!!
    //  g_signal_connect (win, "destroy", gtk_main_quit, NULL);

    /* Create a vertical box with buttons */
    vbox = gtk_vbox_new (TRUE, 10);
    gtk_container_add (GTK_CONTAINER (win), vbox);
    button = gtk_button_new_from_stock (GTK_STOCK_DIALOG_INFO);
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (about), (gpointer) win);
    gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
    button = gtk_button_new_from_stock (GTK_STOCK_CLOSE);
    g_signal_connect (button, "clicked", gtk_main_quit, NULL);
    gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

    /* Enter the main loop */
    gtk_widget_show_all (win);
}

int main (int argc, char *argv[])
{
    /* Initialize GTK+ */
    g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
    gtk_init (&argc, &argv);
    g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);


    /* Replace the line below with a command to call the main screen when we have one */
	simplemenu(NULL,NULL);

    /* Main loop */
    gtk_main ();
    return 0;
}
