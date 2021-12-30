**1. Chức năng: chức năng yêu cầu + chức năng thêm (nếu có)**

- Chức năng cơ bản của Calculator là cộng trừ nhân chia.
- Có khả năng tính số thập phân, clear screen.
- Có giao diện người dùng.

**2. Flow cơ bản của chương trình -> Event Driven là gì?**

- Flow cơ bản của chương trình là tạo ra các Button, và bắt sự kiện khi người dùng click vào Button đó thì sẽ chạy hàm được viết tại Button đó, hàm này sẽ gán các giá trị cho biến number được tạo sẵn để tính toán. Khi người dùng click vào Button Equal thì chương trình sẽ thực hiện tính toán ra kết quả, cuối cùng là in ra kết quả tại cửa sổ Text cho người dùng xem được.
    => Event-Driven là một mô hình lập trình trong đó Flow của chương trình được xác định bởi các sự kiện như hành động người dùng (Click, bấm phím), sau đó chương trình sẽ thực hiện xử lý logic đã được cài đặt sẵn.

**3. Điểm cộng và trừ của Event-Driven.**

- Điểm cộng: 

             + Linh hoạt: chương trình sử dụng ED thường sẽ dễ thay đổi hơn khi cần.

             + Phù hợp với kéo thả: Chương trình sử dụng ED sẽ cho phép người dùng kéo thả các đối tượng như Button, Label, Text Area ở Toolbox.

             + Giảm thiểu tài nguyên sử dụng

             + Ví dụ: Chương trình làm bằng cách kéo thả các Button tại toolbox thay vì phải code từng đối tượng.

-  Điểm trừ: 

             + Phức tạp: kiến trúc của ED khá phực tạp hơn so với các kiến trúc khác

             + Chậm: với những chương trình phức tạp thì kiến trúc ED thường sẽ chậm hơn.

             + Khó tìm lỗi.
             
             + Ví dụ: Chương trình viết bằng kiến trúc ED hơi phức tạp và khó khăn cho người mới, em đã phải tìm rất nhiều tutorials để ngâm cứu cái
             MFC và Event-Driven.
