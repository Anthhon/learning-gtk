#include<gtk/gtk.h>

static void print_hello ( GtkWidget *widget, gpointer data ){
		g_print("Hello, World\n");
}

static void activate ( GtkApplication *app, gpointer user_data ){
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *grid;

  // Creates a new window and set its title
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW(window), "Grid");

  // Here we construct the container that is going pack our buttons
  grid = gtk_grid_new();

  // Pack the container in the window
  gtk_window_set_child ( GTK_WINDOW (window), grid);

  button = gtk_button_new_with_label ("Click me"); // Set a label for 'button'
  g_signal_connect ( button, "clicked", G_CALLBACK(print_hello), NULL ); // Calls 'print_hello' when 'button' is clicked
  // Place button in position (0, 0) and make it fill
  // 1 cell horizontally and 1 cell vertically
  gtk_grid_attach ( GTK_GRID (grid), button, 0, 0, 2, 1 );

  // Creates another button in the same model
  button = gtk_button_new_with_label ("Quit");
  g_signal_connect_swapped ( button, "clicked", G_CALLBACK ( gtk_window_destroy ), window);
  gtk_grid_attach ( GTK_GRID (grid), button, 0, 1, 2, 1 );

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
