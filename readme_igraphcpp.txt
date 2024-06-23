 the feature branch igraphcpp contains routiones tha call the igraph.h header but that are not needed for 
the rest of the fucntions. 
this creates useless troubles with the packageing and location of the igraph.h file  
Therefore in teh production versions the fucntions 
- er_diameter()
- giant_component() 

have been removed, even if the R version of the latter at some point gave problems with the Calley tree  

This has been kep as a working branch to clean up a production main. 

