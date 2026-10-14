# MP3 Tag Reader and Editor in C

## About the Project

This is a C program for viewing and editing ID3 tag information in MP3 files. It can display details such as the song title, artist, album, year, genre, and comments. It also allows selected tag values to be changed from the command line.

## Features

- View tag information stored in an MP3 file
- Edit supported tags such as title, artist, album, year, and comment
- Check command-line arguments and show usage instructions
- Use separate source files for viewing and editing
- Work with MP3 files that contain ID3v2 tags

## Technologies Used

- C programming
- GCC compiler
- File handling
- Structures, pointers, and command-line arguments
- ID3 tag data processing

## Project Files

```text
MP3-Tag-Reader/
├── MP3_main.c
├── MP3_view.c
├── MP3_edit.c
├── MP3_header.h
└── sample.mp3
```

## Compile the Program

Open a terminal in the project folder and run:

```bash
gcc MP3_main.c MP3_view.c MP3_edit.c -o mp3tag
```

Make sure GCC is installed before compiling.

## Usage

### View MP3 tag information

```bash
./mp3tag -v sample.mp3
```

### Show help

```bash
./mp3tag --help
```

### Edit a title

```bash
./mp3tag -e -t "New Song Title" sample.mp3
```

### Edit an artist

```bash
./mp3tag -e -a "Artist Name" sample.mp3
```

### Edit an album

```bash
./mp3tag -e -A "Album Name" sample.mp3
```

### Edit the year

```bash
./mp3tag -e -y "2026" sample.mp3
```

### Edit the comment

```bash
./mp3tag -e -c "My comment" sample.mp3
```

The edit operation changes the selected tag in the MP3 file. Keep a backup of your original MP3 before testing edits.

## What I Learned

- Reading and writing files in C
- Processing binary data
- Working with command-line arguments
- Splitting a program into source and header files
- Reading and updating MP3 tag information

## Author

C Manu

## Note

This project was created for learning and educational purposes. Test it with a copy of an MP3 file to avoid losing your original data.
