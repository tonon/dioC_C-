#include <gtk/gtk.h>
#include "calc.h"
#include "convert.h"

void on_add_button_clicked(GtkWidget *widget, gpointer data) {
    // Implementar a lógica para o botão de adição
}

void on_subtract_button_clicked(GtkWidget *widget, gpointer data) {
    // Implementar a lógica para o botão de subtração
}

void on_multiply_button_clicked(GtkWidget *widget, gpointer data) {
    // Implementar a lógica para o botão de multiplicação
}

void on_divide_button_clicked(GtkWidget *widget, gpointer data) {
    // Implementar a lógica para o botão de divisão
}

void create_calculator_interface(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *add_button, *subtract_button, *multiply_button, *divide_button;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calculadora de Programador");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    add_button = gtk_button_new_with_label("Add");
    g_signal_connect(add_button, "clicked", G_CALLBACK(on_add_button_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), add_button, 0, 0, 1, 1);

    subtract_button = gtk_button_new_with_label("Subtract");
    g_signal_connect(subtract_button, "clicked", G_CALLBACK(on_subtract_button_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), subtract_button, 1, 0, 1, 1);

    multiply_button = gtk_button_new_with_label("Multiply");
    g_signal_connect(multiply_button, "clicked", G_CALLBACK(on_multiply_button_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), multiply_button, 0, 1, 1, 1);

    divide_button = gtk_button_new_with_label("Divide");
    g_signal_connect(divide_button, "clicked", G_CALLBACK(on_divide_button_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), divide_button, 1, 1, 1, 1);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();
}
