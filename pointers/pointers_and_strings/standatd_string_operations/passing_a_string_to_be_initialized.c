char *format(char *buffer, size_t size, const char* name, size_t quantity, size_t weight) {
    snprintf(buffer, size, "Item: %s Quantity: %u Weight: %u", name, quantity, weight);
    return buffer;
}

/*
The snprintf function was used as a simple way of formatting the string. This function
writes to the buffer provided by the first parameter. The second argument specifies the
buffer’s size. This function will not write past the end of the buffer. Otherwise, the
function behaves the same way as printf.
*/