//Main.cpp
//Author: Andrew Choi
//Purpose: Main class acts as a driver and 
//         includes a few modified methods from 
//         previous assignment(program3) images 
//			class
#include <iostream>
#include "Container.h"
#include "Images.h"


//recursiveContainer: Groups segments of the image in differenct containrs to create new image
//Precondition: input imageand output  have non negative dimentions. pixel has valid number of bytes
//Postcondition: Returns a new output image by recursively placing similar pixel segments in contatiners.
//							 Output is the average of colors in the segements
Images recursiveContainer(Container& superContainer, Container& current, Images& input, Images& output, Container::pixelz& seed, int & layer, int &numSeeds)
{
	//Checks to see if the seed pixel is within image bounds
	if (seed.row < 0 || seed.row >= input.getRow() || seed.column < 0 || seed.column >= input.getCol())
	{
		//cout << "base1" << endl;
		return output;
	}

	if (input.getPixel(seed.row, seed.column).red == 255 && input.getPixel(seed.row, seed.column).green == 0 && input.getPixel(seed.row, seed.column).blue == 0)
	{
		//cout << "base3" << endl;
		return output;
	}

	if ((abs(seed.red - input.getPixel(seed.row, seed.column).red) + abs(seed.green - input.getPixel(seed.row, seed.column).green) + abs(seed.blue - input.getPixel(seed.row, seed.column).blue)) >= 100)
	{
		//cout << "base2" << endl;
		return output;
	}


	current.addPixel(seed);
	//cout << (int)input.getPixel(seed.row, seed.column).red << "Row " << seed.row << "column " << seed.column << endl;
    input.setPixel(255, 0, 0, seed.row, seed.column);
	//cout << (int)input.getPixel(seed.row, seed.column).red <<"Row " <<  seed.row << "column "<< seed.column<<endl;

//	int numSeeds= 0;

	//cout << layer << endl;
	//cout << " Row: " << seed.row << "Column : " << seed.column << endl;
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	if (layer == 0)
	{
		//Find new seed pixel 
		for (int row = seed.row; row < input.getRow(); row++)
		{
 			for (int col = seed.column; col < input.getCol(); col++)
			{
				cout << " Row: " << row << " Col: " << col <<endl;
				cout << "Red: " << (int)input.getPixel(row, col).red << endl;
		
				//set new row and col to new seeds row and col and the colors
				if (input.getPixel(row, col).red != 255 && input.getPixel(row, col).green != 0 && input.getPixel(row, col).blue != 0)
				{
					cout << "SEED: " << row << " "<< col<< endl;
					seed.red = input.getPixel(row, col).red;
					seed.green = input.getPixel(row, col).green;
					seed.blue = input.getPixel(row, col).blue;
					seed.row = row;
					seed.column = col;

					seed.row = seed.row + 1;
					layer++;
				   recursiveContainer(superContainer, current, input, output, seed, layer,numSeeds);

					seed.row = seed.row - 1;
					seed.column = seed.column + 1;
					recursiveContainer(superContainer, current, input, output, seed, layer, numSeeds);

					seed.column = seed.column - 1;
					seed.row = seed.row - 1;
					recursiveContainer(superContainer, current, input, output, seed, layer, numSeeds);

					seed.row = seed.row + 1;
					seed.column = seed.column - 1;
					recursiveContainer(superContainer, current, input, output, seed, layer, numSeeds);
					seed.column = seed.column + 1;

					layer = 0;
					//cout << "Number of Seeds " << numSeeds << endl;
					numSeeds++;

					current.setAvgColor();
					//cout << current.averageRed() << " " << current.averageGreen()<<  " " << current.averageBlue() <<endl;
					superContainer.merge(current);
					//cout << " SIze of supercontainer" << superContainer.size() << endl;
					//cout << "size Before " << current.size() << endl;
					current.emptyList();
					//cout << "size after empty " << superContainer.size() << endl;
					//cout << "size After " << current.size() << endl;

				}
			}
		}

		cout << superContainer.size() << endl;
		Container::pixelz temp;
				while(superContainer.size() != 0)
				{
					temp = superContainer.remove();
					output.setPixel(temp.red, temp.green, temp.blue, temp.row, temp.column);
					//cout << "Red" << temp.red << " Green " << temp.green << " Blue " << temp.blue << " Row " << temp.row << " Column " << temp.column << endl;
				}

		return output;
	}
	// cout << " row: " << seed.row << " col " << seed.column << endl;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	if (layer != 0)
	{	
		layer++;
		seed.row = seed.row + 1;
		recursiveContainer(superContainer, current, input, output, seed, layer, numSeeds);

		seed.row = seed.row - 1;
		seed.column = seed.column + 1;
		recursiveContainer(superContainer, current, input, output, seed, layer, numSeeds);

		seed.column = seed.column - 1;
		seed.row = seed.row - 1;
		recursiveContainer(superContainer, current, input, output, seed, layer , numSeeds);

		seed.row = seed.row + 1;
		seed.column = seed.column - 1;
		recursiveContainer(superContainer, current, input, output, seed, layer, numSeeds);
		seed.column = seed.column + 1;

		//cout << layer << endl;
	   // layer = 0;

	} 
	return output;
}




//main: Test code written in Container.cpp
//Precondition: Container.cpp class exists and has 
//              appropriate methods  
//Postconditions: Test the capabilities stated in the
//               assignment. Reads in image, output dimensions
//               create mirror image, modify pixels, compare
//               images and outputs differences.        
int main()
{

		Images newImage("test4.gif");
		cout << newImage << endl;
		Images blankImage(newImage.getRow(), newImage.getCol());

		//Images finalImage(newImage.getRow(), newImage.getCol());
		//finalImage.outputFile("final.gif");

		Container small;
		Container super;
		Container::pixelz pix;
		pix.red = newImage.getPixel(0, 0).red;
		pix.green = newImage.getPixel(0, 0).green;
		pix.blue = newImage.getPixel(0, 0).blue;
		pix.row = 0;
		pix.column = 0;

		int layer = 0;
		int numSeeds = 0;
		recursiveContainer(small, super, newImage, blankImage, pix, layer, numSeeds );
		 cout << "finished recursion" << endl;
		 cout << "Number of Seeds" <<numSeeds<< endl;
		// cout << "Dimensions " << finalImage << endl;
		 /*
		 for (int row = 0; row < finalImage.getRow(); row++)
		 {
			 for (int col = 0; col < finalImage.getCol(); col++)
			 {
				 cout << "-----------------------------------------------" << endl;
				 cout << "row: " << row << ", col : " << col << endl;
				 cout << finalImage.getPixel(row,col).red << "  " << finalImage.getPixel(row, col).green<< " " << finalImage.getPixel(row, col).blue <<endl;
			 }

		 }
		 */
		   cout << "Recursion finished" << endl;
		   blankImage.outputFile("constructedImage.gif");
		   
}


// Either it's because the 'finalImage' has some memory leaks, or 
// you're opening the constructedImage.gif somewhere else
// The name of the output file shouldn't be a problem since it's outputting 
// because usually output func

