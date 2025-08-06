{\rtf1\ansi\ansicpg1252\cocoartf2822
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 Menlo-Italic;\f1\fnil\fcharset0 Menlo-Regular;\f2\fnil\fcharset0 Menlo-Bold;
}
{\colortbl;\red255\green255\blue255;\red129\green144\blue144;\red252\green244\blue220;\red83\green104\blue112;
\red115\green138\blue4;\red165\green119\blue5;\red37\green146\blue134;\red33\green118\blue199;\red198\green28\blue111;
\red71\green91\blue98;\red189\green54\blue19;}
{\*\expandedcolortbl;;\cssrgb\c57647\c63137\c63137;\cssrgb\c99216\c96471\c89020;\cssrgb\c39608\c48235\c51373;
\cssrgb\c52157\c60000\c0;\cssrgb\c70980\c53725\c0;\cssrgb\c16471\c63137\c59608;\cssrgb\c14902\c54510\c82353;\cssrgb\c82745\c21176\c50980;
\cssrgb\c34510\c43137\c45882;\cssrgb\c79608\c29412\c8627;}
\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\partightenfactor0

\f0\i\fs24 \cf2 \cb3 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 // main.c
\f1\i0 \cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf5 \cb3 \strokec5 #include\cf6 \strokec6  \cf7 \strokec7 <stdio.h>\cf4 \cb1 \strokec4 \
\cf5 \cb3 \strokec5 #include\cf6 \strokec6  \cf7 \strokec7 <stdlib.h>\cf4 \cb1 \strokec4 \
\cf5 \cb3 \strokec5 #include\cf6 \strokec6  \cf7 \strokec7 <stdint.h>\cf4 \cb1 \strokec4 \
\cf5 \cb3 \strokec5 #include\cf6 \strokec6  \cf7 \strokec7 <time.h>\cf4 \cb1 \strokec4 \
\
\cf5 \cb3 \strokec5 #define\cf6 \strokec6  \cf8 \strokec8 WAV_HEADER_SIZE\cf6 \strokec6  \cf9 \strokec9 44\cf4 \cb1 \strokec4 \
\
\
\pard\pardeftab720\partightenfactor0

\f0\i \cf2 \cb3 \strokec2 // Prototypes for \uc0\u956 -law routines
\f1\i0 \cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0

\f2\b \cf10 \cb3 \strokec10 uint8_t
\f1\b0 \cf4 \strokec4   \cf8 \strokec8 MuLawCompress\cf4 \strokec4 (
\f2\b \cf10 \strokec10 int16_t
\f1\b0 \cf4 \strokec4  sample);\cb1 \

\f2\b \cf10 \cb3 \strokec10 int16_t
\f1\b0 \cf4 \strokec4   \cf8 \strokec8 MuLawDecompress\cf4 \strokec4 (
\f2\b \cf10 \strokec10 uint8_t
\f1\b0 \cf4 \strokec4  code);\cb1 \
\
\
\pard\pardeftab720\partightenfactor0

\f0\i \cf2 \cb3 \strokec2 // Top-level I/O routines
\f1\i0 \cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0

\f2\b \cf10 \cb3 \strokec10 void
\f1\b0 \cf4 \strokec4  \cf8 \strokec8 CompressToRaw\cf4 \strokec4 (
\f2\b \cf10 \strokec10 const
\f1\b0 \cf4 \strokec4  
\f2\b \cf10 \strokec10 char
\f1\b0 \cf4 \strokec4  \cf5 \strokec5 *\cf4 \strokec4 wavPath, 
\f2\b \cf10 \strokec10 const
\f1\b0 \cf4 \strokec4  
\f2\b \cf10 \strokec10 char
\f1\b0 \cf4 \strokec4  \cf5 \strokec5 *\cf4 \strokec4 rawPath);\cb1 \

\f2\b \cf10 \cb3 \strokec10 void
\f1\b0 \cf4 \strokec4  \cf8 \strokec8 DecompressFromRaw\cf4 \strokec4 (
\f2\b \cf10 \strokec10 const
\f1\b0 \cf4 \strokec4  
\f2\b \cf10 \strokec10 char
\f1\b0 \cf4 \strokec4  \cf5 \strokec5 *\cf4 \strokec4 rawPath, 
\f2\b \cf10 \strokec10 const
\f1\b0 \cf4 \strokec4  
\f2\b \cf10 \strokec10 char
\f1\b0 \cf4 \strokec4  \cf5 \strokec5 *\cf4 \strokec4 wavPath);\cb1 \
\
\pard\pardeftab720\partightenfactor0

\f0\i \cf2 \cb3 \strokec2 // Main
\f1\i0 \cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0

\f2\b \cf10 \cb3 \strokec10 int
\f1\b0 \cf4 \strokec4  \cf8 \strokec8 main\cf4 \strokec4 (
\f2\b \cf10 \strokec10 int
\f1\b0 \cf4 \strokec4  argc, 
\f2\b \cf10 \strokec10 char
\f1\b0 \cf4 \strokec4  \cf5 \strokec5 *\cf4 \strokec4 argv
\f2\b \cf10 \strokec10 []
\f1\b0 \cf4 \strokec4 ) \{\cb1 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3     
\f2\b \cf10 \strokec10 const
\f1\b0 \cf4 \strokec4  
\f2\b \cf10 \strokec10 char
\f1\b0 \cf4 \strokec4  \cf5 \strokec5 *\cf4 \strokec4 INPUT_WAV      \cf5 \strokec5 =\cf4 \strokec4  \cf7 \strokec7 "input.wav"\cf4 \strokec4 ;
\f0\i \cf2 \strokec2  // placeholder filepaths
\f1\i0 \cf4 \cb1 \strokec4 \
\cb3     
\f2\b \cf10 \strokec10 const
\f1\b0 \cf4 \strokec4  
\f2\b \cf10 \strokec10 char
\f1\b0 \cf4 \strokec4  \cf5 \strokec5 *\cf4 \strokec4 COMPRESSED_RAW \cf5 \strokec5 =\cf4 \strokec4  \cf7 \strokec7 "compressed.raw"\cf4 \strokec4 ;\cb1 \
\cb3     
\f2\b \cf10 \strokec10 const
\f1\b0 \cf4 \strokec4  
\f2\b \cf10 \strokec10 char
\f1\b0 \cf4 \strokec4  \cf5 \strokec5 *\cf4 \strokec4 OUTPUT_WAV     \cf5 \strokec5 =\cf4 \strokec4  \cf7 \strokec7 "output.wav"\cf4 \strokec4 ;\cb1 \
\
\cb3     
\f2\b \cf10 \strokec10 clock_t
\f1\b0 \cf4 \strokec4  startC \cf5 \strokec5 =\cf4 \strokec4  \cf8 \strokec8 clock\cf4 \strokec4 ();
\f0\i \cf2 \strokec2  // compression stopwatch
\f1\i0 \cf4 \cb1 \strokec4 \
\cb3     \cf8 \strokec8 CompressToRaw\cf4 \strokec4 (INPUT_WAV, COMPRESSED_RAW);\cb1 \
\cb3     
\f2\b \cf10 \strokec10 clock_t
\f1\b0 \cf4 \strokec4  endC   \cf5 \strokec5 =\cf4 \strokec4  \cf8 \strokec8 clock\cf4 \strokec4 ();\cb1 \
\
\cb3     
\f2\b \cf10 \strokec10 clock_t
\f1\b0 \cf4 \strokec4  startD \cf5 \strokec5 =\cf4 \strokec4  \cf8 \strokec8 clock\cf4 \strokec4 ();
\f0\i \cf2 \strokec2  // decompression stopwatch
\f1\i0 \cf4 \cb1 \strokec4 \
\cb3     \cf8 \strokec8 DecompressFromRaw\cf4 \strokec4 (COMPRESSED_RAW, OUTPUT_WAV);\cb1 \
\cb3     
\f2\b \cf10 \strokec10 clock_t
\f1\b0 \cf4 \strokec4  endD   \cf5 \strokec5 =\cf4 \strokec4  \cf8 \strokec8 clock\cf4 \strokec4 ();\cb1 \
\
\cb3     
\f2\b \cf10 \strokec10 double
\f1\b0 \cf4 \strokec4  tC \cf5 \strokec5 =\cf4 \strokec4  (
\f2\b \cf10 \strokec10 double
\f1\b0 \cf4 \strokec4 )(endC   \cf5 \strokec5 -\cf4 \strokec4  startC) \cf5 \strokec5 /\cf4 \strokec4  CLOCKS_PER_SEC;\cb1 \
\cb3     
\f2\b \cf10 \strokec10 double
\f1\b0 \cf4 \strokec4  tD \cf5 \strokec5 =\cf4 \strokec4  (
\f2\b \cf10 \strokec10 double
\f1\b0 \cf4 \strokec4 )(endD   \cf5 \strokec5 -\cf4 \strokec4  startD) \cf5 \strokec5 /\cf4 \strokec4  CLOCKS_PER_SEC;\cb1 \
\cb3     
\f2\b \cf10 \strokec10 double
\f1\b0 \cf4 \strokec4  tT \cf5 \strokec5 =\cf4 \strokec4  (
\f2\b \cf10 \strokec10 double
\f1\b0 \cf4 \strokec4 )(endD   \cf5 \strokec5 -\cf4 \strokec4  startC) \cf5 \strokec5 /\cf4 \strokec4  CLOCKS_PER_SEC;
\f0\i \cf2 \strokec2  // calculates total elapsed time
\f1\i0 \cf4 \cb1 \strokec4 \
\
\cb3     \cf8 \strokec8 printf\cf4 \strokec4 (\cf7 \strokec7 "Compression time:   \cf11 \strokec11 %.3f\cf7 \strokec7  s\cf11 \strokec11 \\n\cf7 \strokec7 "\cf4 \strokec4 , tC);\cb1 \
\cb3     \cf8 \strokec8 printf\cf4 \strokec4 (\cf7 \strokec7 "Decompression time: \cf11 \strokec11 %.3f\cf7 \strokec7  s\cf11 \strokec11 \\n\cf7 \strokec7 "\cf4 \strokec4 , tD);\cb1 \
\cb3     \cf8 \strokec8 printf\cf4 \strokec4 (\cf7 \strokec7 "Total time:         \cf11 \strokec11 %.3f\cf7 \strokec7  s\cf11 \strokec11 \\n\cf7 \strokec7 "\cf4 \strokec4 , tT);\cb1 \
\
\cb3     \cf5 \strokec5 return\cf4 \strokec4  \cf9 \strokec9 0\cf4 \strokec4 ;\cb1 \
\cb3 \}\cb1 \
\
\pard\pardeftab720\partightenfactor0

\f0\i \cf2 \cb3 \strokec2 //----------------------------------------------------------------------
\f1\i0 \cf4 \cb1 \strokec4 \

\f0\i \cf2 \cb3 \strokec2 // Read WAV header, then encode every 16-bit sample to 8-bit \uc0\u956 -law
\f1\i0 \cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0

\f2\b \cf10 \cb3 \strokec10 void
\f1\b0 \cf4 \strokec4  \cf8 \strokec8 CompressToRaw\cf4 \strokec4 (
\f2\b \cf10 \strokec10 const
\f1\b0 \cf4 \strokec4  
\f2\b \cf10 \strokec10 char
\f1\b0 \cf4 \strokec4  \cf5 \strokec5 *\cf4 \strokec4 wavPath, 
\f2\b \cf10 \strokec10 const
\f1\b0 \cf4 \strokec4  
\f2\b \cf10 \strokec10 char
\f1\b0 \cf4 \strokec4  \cf5 \strokec5 *\cf4 \strokec4 rawPath) \{\cb1 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3     FILE \cf5 \strokec5 *\cf4 \strokec4 wav \cf5 \strokec5 =\cf4 \strokec4  \cf8 \strokec8 fopen\cf4 \strokec4 (wavPath, \cf7 \strokec7 "rb"\cf4 \strokec4 );\cb1 \
\cb3     \cf5 \strokec5 if\cf4 \strokec4  (\cf5 \strokec5 !\cf4 \strokec4 wav) \{\cb1 \
\cb3         \cf8 \strokec8 perror\cf4 \strokec4 (\cf7 \strokec7 "fopen(input.wav)"\cf4 \strokec4 );\cb1 \
\cb3         \cf8 \strokec8 exit\cf4 \strokec4 (EXIT_FAILURE);\cb1 \
\cb3     \}\cb1 \
\
\cb3     
\f0\i \cf2 \strokec2 // Skip over the 44-byte WAV header
\f1\i0 \cf4 \cb1 \strokec4 \
\cb3     
\f2\b \cf10 \strokec10 uint8_t
\f1\b0 \cf4 \strokec4  header[WAV_HEADER_SIZE];\cb1 \
\cb3     \cf5 \strokec5 if\cf4 \strokec4  (\cf8 \strokec8 fread\cf4 \strokec4 (header, \cf9 \strokec9 1\cf4 \strokec4 , WAV_HEADER_SIZE, wav) \cf5 \strokec5 !=\cf4 \strokec4  WAV_HEADER_SIZE) \{\cb1 \
\cb3         \cf8 \strokec8 fprintf\cf4 \strokec4 (stderr, \cf7 \strokec7 "Error reading WAV header\cf11 \strokec11 \\n\cf7 \strokec7 "\cf4 \strokec4 );\cb1 \
\cb3         \cf8 \strokec8 fclose\cf4 \strokec4 (wav);\cb1 \
\cb3         \cf8 \strokec8 exit\cf4 \strokec4 (EXIT_FAILURE);\cb1 \
\cb3     \}\cb1 \
\
\cb3     FILE \cf5 \strokec5 *\cf4 \strokec4 raw \cf5 \strokec5 =\cf4 \strokec4  \cf8 \strokec8 fopen\cf4 \strokec4 (rawPath, \cf7 \strokec7 "wb"\cf4 \strokec4 );\cb1 \
\cb3     \cf5 \strokec5 if\cf4 \strokec4  (\cf5 \strokec5 !\cf4 \strokec4 raw) \{\cb1 \
\cb3         \cf8 \strokec8 perror\cf4 \strokec4 (\cf7 \strokec7 "fopen(compressed.raw)"\cf4 \strokec4 );\cb1 \
\cb3         \cf8 \strokec8 fclose\cf4 \strokec4 (wav);\cb1 \
\cb3         \cf8 \strokec8 exit\cf4 \strokec4 (EXIT_FAILURE);\cb1 \
\cb3     \}\cb1 \
\
\cb3     
\f2\b \cf10 \strokec10 int16_t
\f1\b0 \cf4 \strokec4  sample;\cb1 \
\cb3     \cf5 \strokec5 while\cf4 \strokec4  (\cf8 \strokec8 fread\cf4 \strokec4 (\cf5 \strokec5 &\cf4 \strokec4 sample, \cf5 \strokec5 sizeof\cf4 \strokec4 (sample), \cf9 \strokec9 1\cf4 \strokec4 , wav) \cf5 \strokec5 ==\cf4 \strokec4  \cf9 \strokec9 1\cf4 \strokec4 ) \{\cb1 \
\cb3         
\f2\b \cf10 \strokec10 uint8_t
\f1\b0 \cf4 \strokec4  code \cf5 \strokec5 =\cf4 \strokec4  \cf8 \strokec8 MuLawCompress\cf4 \strokec4 (sample);\cb1 \
\cb3         \cf8 \strokec8 fwrite\cf4 \strokec4 (\cf5 \strokec5 &\cf4 \strokec4 code, \cf5 \strokec5 sizeof\cf4 \strokec4 (code), \cf9 \strokec9 1\cf4 \strokec4 , raw);\cb1 \
\cb3     \}\cb1 \
\
\cb3     \cf8 \strokec8 fclose\cf4 \strokec4 (raw);\cb1 \
\cb3     \cf8 \strokec8 fclose\cf4 \strokec4 (wav);\cb1 \
\cb3 \}\cb1 \
\
\pard\pardeftab720\partightenfactor0

\f0\i \cf2 \cb3 \strokec2 //----------------------------------------------------------------------
\f1\i0 \cf4 \cb1 \strokec4 \

\f0\i \cf2 \cb3 \strokec2 // Re-read original WAV header, write it out (adjusted for 16-bit PCM),
\f1\i0 \cf4 \cb1 \strokec4 \

\f0\i \cf2 \cb3 \strokec2 // then decode every \uc0\u956 -law byte back into a 16-bit sample
\f1\i0 \cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0

\f2\b \cf10 \cb3 \strokec10 void
\f1\b0 \cf4 \strokec4  \cf8 \strokec8 DecompressFromRaw\cf4 \strokec4 (
\f2\b \cf10 \strokec10 const
\f1\b0 \cf4 \strokec4  
\f2\b \cf10 \strokec10 char
\f1\b0 \cf4 \strokec4  \cf5 \strokec5 *\cf4 \strokec4 rawPath, 
\f2\b \cf10 \strokec10 const
\f1\b0 \cf4 \strokec4  
\f2\b \cf10 \strokec10 char
\f1\b0 \cf4 \strokec4  \cf5 \strokec5 *\cf4 \strokec4 wavPath) \{\cb1 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3     
\f0\i \cf2 \strokec2 // Reopen original WAV to grab its header fields
\f1\i0 \cf4 \cb1 \strokec4 \
\cb3     FILE \cf5 \strokec5 *\cf4 \strokec4 orig \cf5 \strokec5 =\cf4 \strokec4  \cf8 \strokec8 fopen\cf4 \strokec4 (\cf7 \strokec7 "input.wav"\cf4 \strokec4 , \cf7 \strokec7 "rb"\cf4 \strokec4 );\cb1 \
\cb3     \cf5 \strokec5 if\cf4 \strokec4  (\cf5 \strokec5 !\cf4 \strokec4 orig) \{\cb1 \
\cb3         \cf8 \strokec8 perror\cf4 \strokec4 (\cf7 \strokec7 "fopen(input.wav for header)"\cf4 \strokec4 );\cb1 \
\cb3         \cf8 \strokec8 exit\cf4 \strokec4 (EXIT_FAILURE);\cb1 \
\cb3     \}\cb1 \
\cb3     
\f2\b \cf10 \strokec10 uint8_t
\f1\b0 \cf4 \strokec4  header[WAV_HEADER_SIZE];\cb1 \
\cb3     \cf5 \strokec5 if\cf4 \strokec4  (\cf8 \strokec8 fread\cf4 \strokec4 (header, \cf9 \strokec9 1\cf4 \strokec4 , WAV_HEADER_SIZE, orig) \cf5 \strokec5 !=\cf4 \strokec4  WAV_HEADER_SIZE) \{\cb1 \
\cb3         \cf8 \strokec8 fprintf\cf4 \strokec4 (stderr, \cf7 \strokec7 "Error reading original WAV header\cf11 \strokec11 \\n\cf7 \strokec7 "\cf4 \strokec4 );\cb1 \
\cb3         \cf8 \strokec8 fclose\cf4 \strokec4 (orig);\cb1 \
\cb3         \cf8 \strokec8 exit\cf4 \strokec4 (EXIT_FAILURE);\cb1 \
\cb3     \}\cb1 \
\cb3     \cf8 \strokec8 fclose\cf4 \strokec4 (orig);\cb1 \
\
\cb3     
\f0\i \cf2 \strokec2 // TODO: adjust header[].bitsPerSample = 16, byteRate, blockAlign, data sizes...
\f1\i0 \cf4 \cb1 \strokec4 \
\cb3     
\f0\i \cf2 \strokec2 //       so that the new WAV header reflects 16-bit PCM data of length = raw file size
\f1\i0 \cf4 \cb1 \strokec4 \
\
\cb3     FILE \cf5 \strokec5 *\cf4 \strokec4 raw \cf5 \strokec5 =\cf4 \strokec4  \cf8 \strokec8 fopen\cf4 \strokec4 (rawPath, \cf7 \strokec7 "rb"\cf4 \strokec4 );\cb1 \
\cb3     \cf5 \strokec5 if\cf4 \strokec4  (\cf5 \strokec5 !\cf4 \strokec4 raw) \{\cb1 \
\cb3         \cf8 \strokec8 perror\cf4 \strokec4 (\cf7 \strokec7 "fopen(compressed.raw)"\cf4 \strokec4 );\cb1 \
\cb3         \cf8 \strokec8 exit\cf4 \strokec4 (EXIT_FAILURE);\cb1 \
\cb3     \}\cb1 \
\cb3     FILE \cf5 \strokec5 *\cf4 \strokec4 wav \cf5 \strokec5 =\cf4 \strokec4  \cf8 \strokec8 fopen\cf4 \strokec4 (wavPath, \cf7 \strokec7 "wb"\cf4 \strokec4 );\cb1 \
\cb3     \cf5 \strokec5 if\cf4 \strokec4  (\cf5 \strokec5 !\cf4 \strokec4 wav) \{\cb1 \
\cb3         \cf8 \strokec8 perror\cf4 \strokec4 (\cf7 \strokec7 "fopen(output.wav)"\cf4 \strokec4 );\cb1 \
\cb3         \cf8 \strokec8 fclose\cf4 \strokec4 (raw);\cb1 \
\cb3         \cf8 \strokec8 exit\cf4 \strokec4 (EXIT_FAILURE);\cb1 \
\cb3     \}\cb1 \
\
\cb3     
\f0\i \cf2 \strokec2 // Write the (possibly adjusted) header into the output WAV
\f1\i0 \cf4 \cb1 \strokec4 \
\cb3     \cf5 \strokec5 if\cf4 \strokec4  (\cf8 \strokec8 fwrite\cf4 \strokec4 (header, \cf9 \strokec9 1\cf4 \strokec4 , WAV_HEADER_SIZE, wav) \cf5 \strokec5 !=\cf4 \strokec4  WAV_HEADER_SIZE) \{\cb1 \
\cb3         \cf8 \strokec8 fprintf\cf4 \strokec4 (stderr, \cf7 \strokec7 "Error writing WAV header\cf11 \strokec11 \\n\cf7 \strokec7 "\cf4 \strokec4 );\cb1 \
\cb3         \cf8 \strokec8 fclose\cf4 \strokec4 (raw);\cb1 \
\cb3         \cf8 \strokec8 fclose\cf4 \strokec4 (wav);\cb1 \
\cb3         \cf8 \strokec8 exit\cf4 \strokec4 (EXIT_FAILURE);\cb1 \
\cb3     \}\cb1 \
\
\cb3     
\f2\b \cf10 \strokec10 uint8_t
\f1\b0 \cf4 \strokec4  code;\cb1 \
\cb3     \cf5 \strokec5 while\cf4 \strokec4  (\cf8 \strokec8 fread\cf4 \strokec4 (\cf5 \strokec5 &\cf4 \strokec4 code, \cf5 \strokec5 sizeof\cf4 \strokec4 (code), \cf9 \strokec9 1\cf4 \strokec4 , raw) \cf5 \strokec5 ==\cf4 \strokec4  \cf9 \strokec9 1\cf4 \strokec4 ) \{\cb1 \
\cb3         
\f2\b \cf10 \strokec10 int16_t
\f1\b0 \cf4 \strokec4  sample \cf5 \strokec5 =\cf4 \strokec4  \cf8 \strokec8 MuLawDecompress\cf4 \strokec4 (code);\cb1 \
\cb3         \cf8 \strokec8 fwrite\cf4 \strokec4 (\cf5 \strokec5 &\cf4 \strokec4 sample, \cf5 \strokec5 sizeof\cf4 \strokec4 (sample), \cf9 \strokec9 1\cf4 \strokec4 , wav);\cb1 \
\cb3     \}\cb1 \
\
\cb3     \cf8 \strokec8 fclose\cf4 \strokec4 (wav);\cb1 \
\cb3     \cf8 \strokec8 fclose\cf4 \strokec4 (raw);\cb1 \
\cb3 \}\cb1 \
\
\pard\pardeftab720\partightenfactor0

\f0\i \cf2 \cb3 \strokec2 //----------------------------------------------------------------------
\f1\i0 \cf4 \cb1 \strokec4 \

\f0\i \cf2 \cb3 \strokec2 // Stubs for \uc0\u956 -law routines\'97replace these 
\f1\i0 \cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0

\f2\b \cf10 \cb3 \strokec10 uint8_t
\f1\b0 \cf4 \strokec4  \cf8 \strokec8 MuLawCompress\cf4 \strokec4 (
\f2\b \cf10 \strokec10 int16_t
\f1\b0 \cf4 \strokec4  sample) \{\cb1 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3     
\f0\i \cf2 \strokec2 // TODO: implement \uc0\u956 -law encoding here
\f1\i0 \cf4 \cb1 \strokec4 \
\cb3     \cf5 \strokec5 return\cf4 \strokec4  \cf9 \strokec9 0\cf4 \strokec4 ;\cb1 \
\cb3 \}\cb1 \
\
\pard\pardeftab720\partightenfactor0

\f2\b \cf10 \cb3 \strokec10 int16_t
\f1\b0 \cf4 \strokec4  \cf8 \strokec8 MuLawDecompress\cf4 \strokec4 (
\f2\b \cf10 \strokec10 uint8_t
\f1\b0 \cf4 \strokec4  code) \{\cb1 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3     
\f0\i \cf2 \strokec2 // TODO: implement \uc0\u956 -law decoding here
\f1\i0 \cf4 \cb1 \strokec4 \
\cb3     \cf5 \strokec5 return\cf4 \strokec4  \cf9 \strokec9 0\cf4 \strokec4 ;\cb1 \
\cb3 \}\cb1 \
\
}