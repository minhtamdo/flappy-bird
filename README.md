# 🎮 Flappy Bird Game on STM32F429I-DISC1 using TouchGFX

Dự án này là phiên bản đơn giản của trò chơi Flappy Bird được phát triển cho bo mạch STM32F429I-DISC1. Giao diện được thiết kế bằng TouchGFX, và chương trình được phát triển và nạp thông qua STM32CubeIDE. Hướng dẫn dưới đây sẽ giúp bạn cài đặt và chạy game trên thiết bị thật.
---

## 1. 🛠️ Cài đặt công cụ phát triển

Để biên dịch và lập trình cho vi điều khiển STM32, cần cài đặt các công cụ sau:

### ✅ STM32CubeIDE

- **Trang chủ:** [https://www.st.com/en/development-tools/stm32cubeide.html](https://www.st.com/en/development-tools/stm32cubeide.html)
- IDE chính thức của STMicroelectronics, hỗ trợ cấu hình ngoại vi, viết mã, biên dịch và nạp chương trình vào vi điều khiển STM32.
- Sau khi tải về và cài đặt, cần khởi động phần mềm để hoàn tất cấu hình ban đầu.

### ✅ TouchGFX Designer

- **Trang chủ:** [https://www.st.com/en/development-tools/touchgfx.html](https://www.st.com/en/development-tools/touchgfx.html)
- Phần mềm thiết kế giao diện đồ họa cho các dòng MCU STM32.
- Nên cài đặt song song với STM32CubeMX để tích hợp vào STM32CubeIDE.

---

## 2. ⬇️ Tải project từ GitHub

Mã nguồn project được lưu trữ tại GitHub. Người dùng có thể tải về bằng cách git clone project này.

## 3. 📂 Mở project trong STM32CubeIDE

Sau khi đã tải mã nguồn về máy, bạn cần mở project bằng phần mềm STM32CubeIDE để biên dịch và nạp chương trình.

### Các bước thực hiện:

- Mở phần mềm **STM32CubeIDE**.
- Trên thanh menu, chọn:  
  `File → Open Projects from File System...`
- Trong cửa sổ hiện ra, nhấn nút **Directory...** và chọn thư mục đã lưu project

- STM32CubeIDE sẽ tự động nhận diện project và hiển thị trong danh sách.
- Nhấn **Finish** để hoàn tất quá trình import project.

Sau khi mở thành công, bạn sẽ thấy mã nguồn và cấu trúc thư mục trong cửa sổ Project Explorer.

---

## 4. 🔌 Nạp chương trình vào STM32F429I-DISCO

Sau khi đã mở project, bạn có thể tiến hành nạp chương trình vào bo mạch STM32F429I-DISCO.

### Các bước thực hiện:

- Kết nối bo mạch **STM32F429I-DISCO** với máy tính qua cáp USB.
- Trong STM32CubeIDE, đảm bảo project đang được chọn.
- Nhấn nút **Run** (hoặc **Debug**) trên thanh công cụ.
- STM32CubeIDE sẽ tiến hành:
  - Biên dịch mã nguồn.
  - Nạp chương trình vào vi điều khiển thông qua cổng USB.

- Chờ quá trình nạp hoàn tất.

Khi chương trình đã được nạp thành công, **màn hình LCD trên board sẽ hiển thị giao diện của game Flappy Bird** và bạn có thể bắt đầu tương tác với trò chơi ngay trên thiết bị.
