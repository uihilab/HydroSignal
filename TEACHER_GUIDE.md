# HydroSignal Teacher's Guide  
A step-by-step guide for K-12 educators to implement HydroSignal in classrooms.  

---

## 📖 About This Guide  
This guide simplifies classroom implementation. **For technical details (code upload, advanced configurations)**, refer to the [HydroSignal README](./README.md).  

---

## Material Requirements  
- **ESP32 NodeMCU**: A microcontroller for data communication ([Purchase Link](https://www.adafruit.com/product/5310)).  
- **Servo Motor**: Drives the indicator needle ([Purchase Link](https://www.adafruit.com/product/169)).  
- **Connection Cables**: Secure component connections ([Purchase Link](https://www.adafruit.com/product/1953)).  

> **Note**: All materials are available via the links above.  

---

## Basic Setup Steps  

### 1. Preparing the Device  
- Connect the servo motor to **GPIO Pin 12** on the ESP32 *(see [Connections in README](./README.md#connections))*.  
- Connect the ESP32 to your computer via USB cable.  

### 2. Website Registration  
1. Visit [HydroSignal Web Interface](https://hydroinformatics.uiowa.edu/lab/hydrosignal/).  
2. Create an account using **"Sign Up"**.  
3. Navigate to **"Devices"** and click **"Add New"** *(details in [Device Registration](./README.md#device-registration))*.  

### 3. Device Configuration  
- **Name**: Assign a descriptive name (e.g., "Classroom Rain Gauge").  
- **Data Source URL**: Enter your hydrological data service URL.  
- **Value Ranges**: Set minimum/maximum data and servo angles.  
- **API Key**: Save the generated key for firmware *(see [Firmware Upload](./README.md#firmware-upload))*.  

### 4. WiFi Setup  
1. Power the device and connect to its WiFi network (via phone/computer).  
2. Open a browser and enter the device’s IP address.  
3. Configure your school’s WiFi credentials *(full steps in [WiFi Settings](./README.md#wifi-settings))*.  

---

## Classroom Implementation: Rain Gauge Example  

### Preparation (2-3 hours)  
> **Complete before class**  
1. **Print Template**: Use [Rainfall Template](./templates/pdf/box_rainfall.pdf).  
2. **Assemble Model**: Fold/glue the paper model (45-60 minutes).  
3. **Program ESP32**: Upload firmware ([README instructions](./README.md#firmware-upload)).  
4. **Install Servo**: Attach to the model (30 minutes).  
5. **Configure WiFi**: Follow [WiFi Settings Guide](./README.md#wifi-settings).  

---

### Lesson Plan (40 minutes)  

#### 1. Introduction (10 min)  
- Discuss the importance of rainfall measurement.  
- Explain real-time monitoring benefits.  

#### 2. Interactive Session (20 min)  
- Students observe live rainfall data on the [web interface](https://hydroinformatics.uiowa.edu/lab/hydrosignal/).  
- Track servo needle movements as data updates.  
- Calculate daily/weekly averages.  

#### 3. Discussion (10 min)  
- **Sample Questions**:  
  - *“How much rain fell today?”*  
  - *“Is this more or less than last week?”*  
  - *“What does this mean for local water systems?”*  

---

## Teaching Tips  
✅ **Test with Low Values**: Ensure clarity before full-scale use.  
✅ **Encourage Predictions**: Have students guess trends before data reveals.  
✅ **Real-World Connections**: Relate data to local weather events.  

---

## 🔧 Need Technical Help?  
For advanced setup, troubleshooting, or code modifications:  
- Consult the **[HydroSignal README](./README.md)** for detailed technical documentation.  
- File an [issue](https://github.com/uihilab/HydroSignal/issues) or contact us.  