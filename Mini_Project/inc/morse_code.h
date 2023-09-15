#ifndef _MORSE_CODE_H_
#define _MORSE_CODE_H_
#include "binary_tree.h"

/**
 * @brief Build a Morse code tree.
 *
 * This function builds a binary tree for Morse code encoding and decoding.
 *
 * @return A pointer to the root of the Morse code tree.
 */
tree_node_t *build_morse_code_tree();

/**
 * @brief Encode a message to Morse code and write it to a file.
 *
 * This function encodes a message from an input file to Morse code and writes the encoded message to an output file.
 *
 * @param input_filename The name of the input file containing the message.
 *
 * @param output_filename The name of the output file to store the encoded Morse code.
 *
 * @param root The root of the Morse code tree.
 *
 * @return The status of the encoding operation.
 */
int encode_file(const char *input_filename, const char *output_filename, tree_node_t *root);

/**
 * @brief Decode Morse code from a file to plain text and write it to another file.
 *
 * This function decodes Morse code from an input file and writes the decoded plain text to an output file.
 *
 * @param input_file The name of the input file containing the Morse code.
 *
 * @param output_file The name of the output file to store the decoded plain text.
 *
 * @param root The root of the Morse code tree.
 */
void decode_file(const char *input_file, const char *output_file, tree_node_t *root);

/**
 * @brief Decode Morse code entered via the keyboard and write it to a file.
 *
 * This function decodes Morse code entered via the keyboard and writes the decoded plain text to an output file.
 *
 * @param root The root of the Morse code tree.
 *
 * @param output_file The name of the output file to store the decoded plain text.
 */
void decode_keyboard(tree_node_t *root, const char *output_file);

/**
 * @brief Encode a message entered via the keyboard to Morse code and write it to a file.
 *
 * This function encodes a message entered via the keyboard to Morse code and writes the encoded message to an output file.
 *
 * @param output_filename The name of the output file to store the encoded Morse code.
 *
 * @param root The root of the Morse code tree.
 *
 * @return The status of the encoding operation (0 for success, -1 for failure).
 */
int encode_keyboard(const char *output_filename, tree_node_t *root);

#endif