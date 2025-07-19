🎧 DSP Noise Reduction System

This project implements a **Digital Signal Processing (DSP)** noise reduction system using **C++**. It reads a noisy input signal from a file, applies a **median filter** to reduce impulse noise, and writes the cleaned signal to an output file.

---

## 📌 Features

- Median filtering for noise reduction
- File I/O to handle real signal data
- Object-oriented design using C++ templates and inheritance
- Utilizes STL (`vector`, `sort`) for performance and simplicity

---

## 🧠 Concepts Used

- **Median Filter**: A nonlinear filtering technique commonly used to remove noise from signals.
- **File I/O in C++**: Reads signal values from `inputsignal.txt` and writes filtered output to `outputsignal.txt`.
- **OOP with Templates**: Uses abstract base class and templated subclass for flexibility and reusability.
- **Standard Template Library (STL)**: Efficient data handling with vectors and sorting.

---

## 📂 File Structure

DSP-Noise-Reduction/
├── inputsignal.txt # Input signal values (one per line)
├── outputsignal.txt # Filtered output signal
├── main.cpp # Complete C++ source code
├── README.md # Project documentation
└── .gitignore # Git ignore config

## 💻 How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/DSP-Noise-Reduction-System.git
cd DSP-Noise-Reduction-System


2. Add Input Signal
Create a file named inputsignal.txt in the root folder and add signal values, each on a new line.

Example:

10  
11  
250  ← noise spike  
12  
13


3. Compile the Program
Use any C++ compiler:
g++ main.cpp -o dsp_filter


4. Run the Executable
./dsp_filter


5. View the Output
Check outputsignal.txt to see the filtered signal:

10  
11  
12  ← cleaned  
12  
13


⚙️ Configuration
You can customize the window size of the median filter directly in the code:
MedianFilter<double> filter(5); // window size = 5
The window size should be an odd number for a proper median to exist.


🛠️ Tech Stack
Language: C++

Compiler: GCC / Clang / MSVC

Libraries: STL (Standard Template Library)

Development Environment: VS Code / any IDE

🧪 Example Input & Output


inputsignal.txt
100  
102  
300  
104  
105


outputsignal.txt
100  
102  
104  
104  
105
The spike value 300 has been successfully filtered out.
