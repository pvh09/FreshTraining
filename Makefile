all: 
	+$(MAKE) -C 1_Memory_Management_and_Pointers main

	+$(MAKE) -C 2_Data_Structure_and_Algorithms/Basic_searching_and_sorting_algorithms main
	+$(MAKE) -C 2_Data_Structure_and_Algorithms/Data_structures_employee main

	+$(MAKE) -C 3_File_handling/File_manipulation_and_encryption main	
	+$(MAKE) -C 3_File_handling/File_size_calculator main	

	+$(MAKE) -C 4_Library/Static_libraries main	
	+$(MAKE) -C 4_Library/Dynamic_libraries main	

	+$(MAKE) -C 5_Mini_Project_Cryptography main	

clean:
	+$(MAKE) -C 1_Memory_Management_and_Pointers clean

	+$(MAKE) -C 2_Data_Structure_and_Algorithms/Basic_searching_and_sorting_algorithms clean
	+$(MAKE) -C 2_Data_Structure_and_Algorithms/Data_structures_employee clean

	+$(MAKE) -C 3_File_handling/File_manipulation_and_encryption clean	
	+$(MAKE) -C 3_File_handling/File_size_calculator clean	

	+$(MAKE) -C 4_Library/Static_libraries clean	
	+$(MAKE) -C 4_Library/Dynamic_libraries clean	

	+$(MAKE) -C 5_Mini_Project_Cryptography clean