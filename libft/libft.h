/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:23:24 by faaraujo          #+#    #+#             */
/*   Updated: 2023/04/30 17:44:50 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

/******************************************************************************/
/* 				   BONUS				      */
/******************************************************************************/

/**
 * @brief define a linked list node, defining the struct in a recursive manner.
 * @param t_list name of node.
 * @param content variable, which will hold the integer value inside it.
 * @param next which is a pointer that’ll point to the next node in a l. list
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @brief Allocates (with malloc(3)) and returns a new node. The member variable
 * ’content’ is initialized with the value of the parameter ’content’.
 * The variable ’next’ is initialized to NULL.
 * @param content The content to create the node with.
 * @return The new node.
*/
t_list	*ft_lstnew(void *content);

/**
 * @brief Returns the last node of the list.
 * @param lst The beginning of the list.
 * @return Last node of the list.
*/
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’ on the content of
 * each node. Creates a new list resulting of the successive applications of the
 * function ’f’. The ’del’ function is used to delete the content of a node if
 * needed.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content of a node
 * if needed.
 * @return The new list. NULL if the allocation fails.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Adds the node ’new’ at the beginning of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Adds the node ’new’ at the end of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
*/
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Takes as a parameter a node and frees the memory of the node’s content
 * using the function ’del’ given as a parameter and free the node. The memory
 * of ’next’ must not be freed.
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Deletes and frees the given node and every successor of that node,
 * using the function ’del’ and free(3). Finally, the pointer to the list must
 * be set to NULL.
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete the content of the node
*/
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’ on the content of
 * each node.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Counts the number of nodes in a list.
 * @param lst The beginning of the list.
 * @return The length of the list.
*/
int		ft_lstsize(t_list *lst);

/******************************************************************************/
/* 				MANDATORY				      */
/******************************************************************************/

/**
 * @brief Checks if "int c" is a letter
 * @param c Character to be checked
 * @return Returns zero if false, non-zero if true   
*/
int		ft_isalpha(int c);

/**
 * @brief Checks if "int c" is a decimal digit character
 * @param c Character to be checked
 * @return Returns zero if false, non-zero if true   
*/
int		ft_isdigit(int c);

/**
 * @brief Checks if "int c" is a alpha or digit character
 * @param c Character to be checked
 * @return Returns zero if false, non-zero if true   
*/
int		ft_isalnum(int c);

/**
 * @brief Checks if "int c" is a ascii character
 * @param c Character to be checked
 * @return Returns zero if false, non-zero if true   
*/
int		ft_isascii(int c);

/**
 * @brief Checks if "int c" is a printable character
 * @param c Character to be checked
 * @return Returns zero if false, non-zero if true   
*/
int		ft_isprint(int c);

/**
 * @brief Converts a lower-case letter to the corresponding upper-case letter
 * @param c Character to be converted
 * @return The corresponding upper-case letter if there is one; 
 * otherwise, the argument is returned unchanged.  
*/
int		ft_toupper(int c);

/**
 * @brief Converts an upper-case letter to the corresponding lower-case letter
 * @param c Character to be converted
 * @return The corresponding lower-case letter if there is one; 
 * otherwise, the argument is returned unchanged.  
*/
int		ft_tolower(int c);

/**
 * @brief compares only the first (at most) n bytes of s1 and s2. 
 * @param s1 Pointer of string.
 * @param s2 Pointer of string.
 * @param n for comparing len characters
 * @return functions return an integer greater than, equal to, or less than 0, 
 * according as the string s1 is greater than, equal to, or less than the
 * string s2. The comparison is done using unsigned characters, 
 * so that `\200' is greater than `\0'.
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief The atoi() function converts the initial portion of the string pointed
 * to by nptr to int representation.
 * @return The converted value.
*/
int		ft_atoi(const char *ptr);

/**
 * @brief function compares the first n bytes (each interpreted as unsigned
 * char) of the memory areas s1 and s2.
 * @return function returns zero if the two strings are identical, otherwise
 * returns the difference between the first two differing bytes (treated as
 * unsigned char values, so that `\200' is greater than `\0', for example).
 * Zero-length strings are always identical.
*/
int		ft_memcmp(const void *s1, const void *s2, size_t len);

/**
 * @brief function locates the first occurrence	of c (converted	to a char) in
 * the string pointed to by s. The terminating null character is considered part
 * of the string; therefore if c is `\0', the functions locate the terminating 
 * `\0'.
 * @param s Pointer of string.
 * @param c character to be found (converted to char).
 * @return return a pointer to the located character, or NULL if the character 
 * does not appear in the string.
*/
char	*ft_strchr(const char *s, int c);

/**
 * @brief function locates the last occurrence of c (converted to a char) in the
 * string pointed to by s. The terminating null character is considered part of 
 * the string; therefore if c is `\0', the functions locate the terminating `\0'.
 * @param s Pointer of string.
 * @param c character to be found (converted to char).
 * @return return a pointer to the located character, or NULL if the character 
 * does not appear in the string. 
 * The terminating null byte is considered part of the string.
*/
char	*ft_strrchr(const char *s, int c);

/**
 * @brief The strnstr() function locates the	first occurrence of the
 * null-terminated string little in the	string big, where not more than	len
 * characters are searched.  Characters that appear after a `\0' character are
 * not searched. Since the strnstr() function is a FreeBSD specific API,
 * it should only be used when portability is not a concern.
 * @return If little is an empty string, big is returned; if little occurs
 * nowhere in big, NULL is returned; otherwise a pointer to the first character 
 * of the first occurrence of little is returned.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief The strdup() function returns a pointer to a new string which is a
 * duplicate of the string s. Memory for the new string is obtained with
 * malloc(3), and can be freed with free(3).
 * @return On success, the strdup() function returns a pointer to the duplicated
 * string. It returns NULL if insufficient memory was available, with errno set 
 * to indicate the cause of the error.
 * @attention ERRORS --> ENOMEM Insufficient memory available to allocate 
 * duplicate string.
*/
char	*ft_strdup(const char *s);

/**
 * @brief Applies the function ’f’ to each character of the string ’s’, and
 * passing its index as first argument to create a new string (with malloc(3))
 * resulting from successive applications of ’f’.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of ’f’. Returns
 * NULL if the allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Allocates (with malloc(3)) and returns a string representing the
 * integer received as an argument. Negative numbers must be handled
 * @param n the integer to convert.
 * @return The string representing the integer. NULL if the allocation fails.
*/
char	*ft_itoa(int n);

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the string ’s’
 * The substring begins at index ’start’ and is of maximum size ’len’.
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string ’s’.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/** 
 * @brief Allocates (with malloc(3)) and returns a new string, which is the
 * result of the concatenation of ’s1’ and ’s2’.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates (with malloc(3)) and returns a copy of ’s1’ with the
 * characters specified in ’set’ removed from the beginning and the end of the
 * string.
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string. NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates (with malloc(3)) and returns an array of strings obtained by
 * splitting ’s’ using the character ’c’ as a delimiter. The array must end with
 * a NULL pointer.
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split. NULL if the
 * allocation fails.
*/
char	**ft_split(char const *s, char c);

/**
 * @brief Function fills the length of bytes (len) of the memory area pointed to
 * by dst with the constant byte c.
 * @param dst a pointer to the memory block to be filled.
 * @param c the value to be filled into the memory block. This value is
 * converted to an unsigned integer before being copied into memory.
 * @param len the number of bytes to pad.
 * @return a pointer to the memory area dst.
*/
void	*ft_memset(void *dst, int c, size_t len);

/**
 * @brief function writes len zero bytes to the string s.
 * If len is zero, bzero() does	nothing.
 * @param s a pointer to the memory to be filled
 * @param len the size of the block of memory to be filled.
*/
void	ft_bzero(void *s, size_t len);

/**
 * @brief The memcpy() function copies len bytes from string src to string dst.
 * If src and dst overlap, the results are not defined.
 * @return The memcpy() function returns the original value of dst.
*/
void	*ft_memcpy(void *dst, const void *src, size_t len);

/**
 * @brief The  memmove()  function  copies  n  bytes from memory area src to
 * memory area dest.  The memory areas may overlap: copying takes place as
 * though the bytes in src are first copied into a temporary array that does not
 * overlap src or dest, and the bytes are then copied from the temporary array
 * to dest.
 * @return a pointer to dest.
*/
void	*ft_memmove(void *dst, const void *src, size_t len);

/**
 * @brief function locates the first occurrence	of c (converted	to an unsigned
 * char) in string s.
 * @return a pointer to the byte located, or NULL if no such byte exists within
 * len bytes.
*/
void	*ft_memchr(const void *s, int c, size_t len);

/**
 * @brief function allocates memory for an array of nbrs elements
 * of size bytes each and returns a pointer to the allocated memory. The memory
 * is set to zero. If nbrs or size is 0, then calloc() returns either NULL, or 
 * a unique pointer value that can later be successfully passed to free().
 * If the multiplication of nbrs and size would result in integer overflow,
 * then calloc() returns an error. 
 * By contrast, an integer overflow would not be detected in the following call
 * to malloc(), with the result that an incorrectly sized block of memory would
 * be allocated: malloc(nmemb * size);
 * @param nthings numbers of things to allocate
 * @param size length in bytes to each things
 * @return a pointer to the allocated memory, which is suitably aligned for any
 * built-in type. On error, these functions return NULL.
*/
void	*ft_calloc(size_t nthings, size_t size);

/**
 * @brief Outputs the character ’c’ to the given file descriptor.
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
*/
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string ’s’ to the given file descriptor.
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
*/
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string ’s’ to the given file descriptor followed by a
 * newline.
 * @param s The string to output.
 * @param fd The file descriptor on wich to write.
*/
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer ’n’ to the given file descriptor.
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
*/
void	ft_putnbr_fd(int n, int fd);

/**
 * @brief Applies the function ’f’ on each character of the string passed as
 * argument, passing its index as first argument. Each character is passed by 
 * address to ’f’ to be modified if necessary.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Computes the length of the string s excluding the terminating null 
 * byte ('\0').
 * @param s Pointer of string.
 * @return Returns the number of bytes in the string pointed to by s.  
*/
size_t	ft_strlen(const char *s);

/**
 * @brief Function copy and concatenate strings respectively. strlcpy() take the
 * full size of the buffer (not just the length) and guarantee to NUL-terminate
 * the result (as long as size is larger than 0).
 * ---> strlcpy() function copies up to size - 1 characters from the
 * NUL-terminated string src to dst, NUL-terminating the result.
 * @return the total length of the string they tried to create. That means the
 * length of src.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Function copy and concatenate strings respectively. strlcat() take the
 * full size of the buffer (not just the length) and guarantee to NUL-terminate
 * the result (as long as there is at least one byte free in dst).
 * ---> for strlcat() both src and dst must be NUL-terminated.
 * --->  The strlcat() function appends the NUL-terminated string src to the end
 * of dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating
 * the result.
 * @return the total length of the string they tried to create. that means the
 * initial length of dst plus the length of src.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif /* LIBFT_H */