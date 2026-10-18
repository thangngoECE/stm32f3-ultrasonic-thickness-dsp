# STM32F303RCT6 firmware guide

Firmware cho board ultrasonic (STM32F303RCT6). File hex đã build nằm trong thư mục `prebuilt/`.

## 1. Nạp firmware bằng STM32CubeProgrammer

1. Tải và cài **STM32CubeProgrammer** từ trang chủ ST.
2. Cấp nguồn cho board bằng cáp USB-C.
3. Cắm mạch nạp SWD vào **J2**.
4. Mở STM32CubeProgrammer, chọn chế độ **ST-LINK**, nhấn **Connect**.
5. Vào tab **Erase and Program**, chọn file `prebuilt/stm32f303rct6_*.hex`.
6. Nhấn **Start Programming** và đợi thông báo thành công.

## 2. Kiểm tra USB CDC trên máy tính

1. Mở một chương trình serial terminal bất kỳ (PuTTY, Tera Term, RealTerm, ...).
2. Chọn **Virtual COM Port** (cổng COM ảo do board tạo ra, ví dụ `COM5`).
3. Baud rate tùy ý.
4. Nếu firmware chạy đúng, sau khoảng 10 giây sẽ thấy dòng:

   ```
   STM32F3RCT6!
   ```

   Dòng này lặp lại mỗi 10 giây.

## 3. Kiểm tra xung TX ở chân PA8

Nếu có dòng chữ ở bước 2, firmware đã chạy. Tiếp theo kiểm tra xung phát:

1. Dùng máy hiện sóng (oscilloscope) đo chân **PA8**.
2. Kỳ vọng: xung cao khoảng **20.8 ns**, lặp lại mỗi **1 ms** (tần số 1 kHz).
