# Grease-NLGI-2-Pressure-Loss-Calculator
Shall calculate grease (NLGI-II) pressure loss when moving through a pipe. Based on Bingham Plastic. Using Swamee-Aggarwal Equation. 

Type 'g++ -o pressure_check.out pressure_check.cpp' 
and
Type 'g++ -o g++ -o grease_specs.out grease_specs.cpp' in terminal to compile the programs

pressure_check HOW TO

Enter 1 for license and program information and 2 to continue -> 1 shows the license and then cotinues with the program 2 skips the license and continues

Enter external dia of pipe in mm -> Self explanatory

Enter thickness in mm -> Self explanatory

Enter vol flow rate in l/hr -> Output given by pump per stroke 

SAMPLE OUTPUT

Pressure loss in a metre of pipe of OD 30 mm and thickness 3mm is 0.784702 bar




grease_specs HOW TO

Enter 1 for license and program information 
 2 to continue -> 1 shows the license and then cotinues with the program 2 skips the license and continues
 
 Enter the no. of different pipes used. -> Enter the different sizes of pipes used.
 
 For pipe 1 (header), 
Enter the Ext dia of pipe (mm) ->. Enter the external diameter of the pipe

Enter the thickness of pipe (mm) -> Self explanatory

Enter the length of pipe (m) -> Self explanatory

For pipe 2,..... same as above for different pipe sizes

Enter the Total number of ports -> Enter the total number of outlets

Enter the average amount of grease required per port per day in cc -> Metering Device output per day per port. 
Enter the number of cycles you want -> Cycles of Grease pump operation
Enter the pump flow rate (in litre/hour) you want to check against -> It shall be checked the output is good enough

SAMPLE OUTPUT to check if pump is suitable

The pump is suitable as far as timing and relieving is concerned. 
The operating time is 0.0916722 hours
 The relieving time is 0.275017 hours 
 The volume to be pumped per day is 1.6501 litre 


Enter 1 to stop, 0 to try again -> Option to run the prgram from begining
Enter vol flow rate in l/hr -> litre per hour pump output

SAMPLE OUTPUT of pressure loss

Pressure loss in a metre of pipe of is 1.41566 bar




 
