#include<fstream>

enum class RWType {
	READ,
	WRITE
};

class OpenFL {
public:
	OpenFL(const OpenFL&) = delete;
	void operator=(const OpenFL&) = delete;

	//How the file is opened. In READ mode, store functions are disabled, and in WRITE mode read functions are disabled
	const RWType fileRWType = RWType::READ;

	//The length of the file (number of characters)
	const size_t len = 0;

	//If false, it means the file has failed to open, or "close()" was called
	const bool isOpen = false;

	const char* filePath = nullptr;

	//Contents of the file stored as a char array, with '\0' added at the end (this won't be used in WRITE mode)
	const char* fileContents = nullptr;

	/// <param name="readWriteType">The way to open the file (read or write mode)</param>
	/// <param name="path">Path to the file</param>
	OpenFL(RWType readWriteType, const char* path) {
		open(readWriteType, path);
	}

	/// <param name="readWriteType">The way to open the file (read or write mode)</param>
	/// <param name="path">Path to the file</param>
	void open(RWType readWriteType, const char* path) {
		if (isOpen)
			close();

		filePath = new char[std::strlen(path) + 1];
		memcpy((char*)filePath, path, std::strlen(path) + 1);

		(*(RWType*)(&fileRWType)) = readWriteType;
		switch (readWriteType) {
		case RWType::READ: {
			std::ifstream f{ path, std::ios::binary | std::ios::ate };
			if (!f.is_open()) {
				(*(bool*)(&isOpen)) = false;
				f.close();
				return;
			}
			else
				(*(bool*)(&isOpen)) = true;

			(*(size_t*)(&len)) = f.tellg();

			f.seekg(0);
			fileContents = new char[len + 1];
			((char*)fileContents)[len] = '\0';
			f.read((char*)fileContents, len);
			f.close();
			break;
		}
		case RWType::WRITE: {
			std::ifstream fchk{ path, std::ios::binary };
			if (!fchk.is_open())
				(*(bool*)(&isOpen)) = false;
			else
				(*(bool*)(&isOpen)) = true;

			fchk.close();

			break;
		}
		default:
			break;
		}
	}

	/// <summary>
	/// Stores a string in the opened file
	/// </summary>
	/// <param name="s">The string to store</param>
	/// <param name="append">If true, instead of overwriting the existing file contents, the given string will be appended to the existing file contents</param>
	void storeString(std::string s, bool append = false) {
		if (fileRWType == RWType::WRITE) {
			std::ofstream* fout;
			if (append)
				fout = new std::ofstream(filePath, std::ios::app);
			else
				fout = new std::ofstream(filePath);
			(*fout) << s;
			fout->close();
			delete fout;
		}
	}

	//Close the file and free loaded file contents if the file was opened in READ mode
	void close() {
		delete[] fileContents;
		fileContents = nullptr;
		delete[] filePath;
		filePath = nullptr;
		(*(bool*)(&isOpen)) = false;
	}

	~OpenFL() {
		close();
	}
};
