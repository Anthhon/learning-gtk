#include<gtk/gtk.h>

static void print_hello ( GtkWidget *widget, gpointer data ){
		g_print("Hello, World\n");
}

static void activate ( GtkApplication *app, gpointer user_data ){
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *box;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW(window), "Hello World");
  gtk_window_set_default_size (GTK_WINDOW(window), 250, 250);

  box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_widget_set_halign (box, GTK_ALIGN_CENTER); // Align button in center
  gtk_widget_set_valign (box, GTK_ALIGN_CENTER); // Sets the horizontal alignment 

  gtk_window_set_child ( GTK_WINDOW (window), box); // Define 'box' as a 'window' child

  button = gtk_button_new_with_label ("Click me"); // Set a label for 'button'

  g_signal_connect ( button, "clicked", G_CALLBACK(print_hello), NULL ); // Calls 'print_hello' when 'button' is clicked

  gtk_box_append ( GTK_BOX (box), button); // Add 'button' as child to 'box'

  gtk_widget_show (window); // Display defined widget
}

int main ( int argc, char **argv ){
  GtkApplication *app;
  int status;

  app = gtk_application_new ( "org.anthony.helloworld", G_APPLICATION_FLAGS_NONE );
  g_signal_connect ( app, "activate", G_CALLBACK (activate), NULL );
  status = g_application_run ( G_APPLICATION (app), argc, argv );
  g_object_unref (app);

  return status;
}
