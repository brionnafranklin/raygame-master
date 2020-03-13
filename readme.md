| Brionna Franklin|
| :---              |
| s198017          |
| Assessment 3 - TikTakToe|
| TikTakToe Documentation |

## I. Design

1. Object Information

   - a collection of data where each piece of data points to the next

    **File**: Iterator.h

        Description: used to move through the list

            Attributes:
            
                -Name: currentNode
                Description: declares a node
                Type: Node<T>*
                Visibility: private
                
            Operations:
                
                -Name: ++
                Description: returns the next thing in the list
                Type: Iterator<T> operator
                Visibility: public
                
                -Name: --
                Description: returns the previous thing in the list
                Type: Iterator<T> operator
                Visibility: public
                
                -Name: 
                Description: 
                Type: 
                Visibility: public
                
                -Name: *
                Description: returns the data at that point in the list
                Type: T operator
                Visibility: public
                
                -Name: 
                Description: 
                Type: 
                Visibility: public
                
                -Name: Iterator
                Description: default constructor
                Type: constructor
                Visibility: public
                
                -Name: ~Iterator
                Description: default deconstructor
                Type: deconstructor
                Visibility: public
                
                -Name: Iterator
                Description: creates a pointer to the current node
                Type: constructor
                Visibility: public
                
                -Name: ==
                Description: checks to see if the currentNode matches inputted another node
                Type: bool operator
                Visibility: public
                
                -Name: !=
                Description: checks to see if the currentNode does not match another inputted node
                Type: bool operator
                Visibility: public
                
    **File**: List.h

        Description: holds data

            Attributes:
            
                -Name: mCout
                Description: used to keep tract of posistion in the list
                Type: int
                Visibility: protected
                
                -Name: m_last
                Description: the last spot in the list
                Type: Node<T>*
                Visibility: protected
                
                -Name: m_first
                Description: the first spot in the list
                Type: Node<T>*
                Visibility: protected
                
                -Name: search
                Description: returns true if node is found
                Type: virtual bool
                Visibility: public
                
                -Name: insertFirst
                Description: adds a node to the beginning of the list
                Type: virtual void
                Visibility: public
                
                -Name: insertLast
                Description: adds a node to the end of the list
                Type: virtual void
                Visibility: public
                
                -Name: deleteNode
                Description: deletes a node
                Type: virtual void
                Visibility: public
                
            Operations:
                
                -Name: initializeList
                Description: set everything in list to nothing
                Type: void
                Visibility: public
                
                -Name: isListEmpty
                Description: checks to see if list is empty
                Type: bool
                Visibility: public
                
                -Name: length
                Description: used to keep tract of how long the list is
                Type: int
                Visibility: public
                
                -Name: front
                Description: returns the info in the first spot of the list
                Type: T
                Visibility: public
                
                -Name: back 
                Description: returns the info in the last spot of the list
                Type: T
                Visibility: public
                
                -Name: begin
                Description: iterates through the list starting with the beginning
                Type: Iterator<T>
                Visibility: public
                
                -Name: end
                Description: iterates through the list starting with the beginning
                Type: Iterator<T>
                Visibility: public
                
                -Name: List
                Description: default constructor
                Type: constructor
                Visibility: public
                
                -Name: ~List
                Description: default deconstructor
                Type: deconstructor
                Visibility: public
                
                -Name: copyList
                Description: copies contents of list
                Type: void
                Visibility: private
                
    **File**: Node.h

        Description: pieces of data that is put into lists

            Attributes:
            
                -Name: info
                Description: the information that is stored in a node
                Type: T
                Visibility: public
                
                -Name: next
                Description: the node that is next in the list
                Type: Node<T> *
                Visibility: public
                
                -Name: previous
                Description: the node that is previous in the list
                Type: Node<T> *
                Visibility: public
                
            Operations:
                
                -Name: Node
                Description: default constructor
                Type: constructor
                Visibility: public
                
                -Name: ~Node
                Description: default deconstructor
                Type: deconstructor
                Visibility: public
                
    **File**: UnorderedList.h

        Description: list that is not ordered
                
            Operations:
                
                -Name: search
                Description: returns true if node is found
                Type: bool
                Visibility: public
                
                -Name: insertFirst
                Description: adds a node to the beginning of the list
                Type: void
                Visibility: public
                
                -Name: insertLast
                Description: adds a node to the end of the list
                Type: void
                Visibility: public
                
                -Name: deleteNode
                Description: deletes a node
                Type: void
                Visibility: public
                
                -Name: clear
                Description: removes everything in the list
                Type: void
                Visibility: public
                
     **File**: main.cpp

        Description: runs on start up; where key functions are called

            Operations:
                
                -Name: main
                Description: runs on start up
                Type: int
                Visibility: private
                
## License

MIT License - Copyright (c) 2018 Academy of Interactive Entertainment

For more information, see the [license][lic] file.

Third party works are attributed under [thirdparty.md][3p].

[lic]:license.md
[3p]:thirdparty.md
[raylib]:https://github.com/raysan5/raylib
