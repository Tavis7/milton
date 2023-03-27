int
main(int argc, char** argv)
{
    char* file_to_open = NULL;
    if ( argc == 2 ) {
        file_to_open = argv[1];
    }
    milton_main(false, file_to_open);
}
