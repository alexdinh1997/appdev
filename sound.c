#include <stdio.h>
#include <math.h>
#include "sound.h"

void showID(char *idname, char *id){
	int i;
	printf("%s : ", idname);
	for(i=0; i<4; i++)
		printf("%c", id[i]);
	puts("");
}

//this function gets one second of samples (16000) and calculates 
//80 pieces of decibels value we know we need to calculate one decibel
// value from 200 samples. decibel value is calculated by RMS flar
void displayWAVDATA(short s[]) {
	double rms[80];
	short *ptr=s;	//we used  a pointer , pointing to the beginning of array
	int i,j;	//for nested loop counters, outeroop repeat 80 times,
			//inner loop repeat 200 times

	for(i=0; i<80;i++) {
		double sum=0;
		for(j=0; j<200;j++){
			sum+= (*ptr) *(*ptr);
			ptr++; //pointing to the next sample 
		}
	rms[i] = sqrt(sum/200);
	printf("rmsd]=%f\n",i,rms[i]);
	}
}
void displayWAVHDR(struct WAVHDR h){
	showID("ChunkID", h.ChunkID);
	printf("Chunk size: %d\n", h.ChunkSize);
	showID("Format", h.Format);
	showID("Subchunk1ID", h.Subchunk1ID);
	printf("Subchunk1 size: %d\n", h.Subchunk1Size);
	printf("Audio Format: %d\n", h.AudioFormat);
	printf("Num. of Channels: %d\n", h.NumChannels);
	printf("Sample rate: %d\n", h.SampleRate);
	printf("Byte rate: %d\n", h.ByteRate);
	printf("Block Align: %d\n", h.BlockAlign);
	printf("Bits per sample: %d\n", h.BitsPerSample);
	showID("Subchunk2ID", h.Subchunk2ID);
	printf("Subchunk2 size: %d\n", h.Subchunk2Size);
}
