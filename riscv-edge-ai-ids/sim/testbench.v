`timescale 1ns/1ps

module testbench;
    reg clk;
    reg rst_n;
    reg [31:0] memory_array [0:262143]; 

    // Khai báo biến đếm chu kỳ xung nhịp
    reg [31:0] cycle_count;

    // Tiến hành đếm số chu kỳ ở mỗi sườn lên của xung nhịp (khi đã thoát reset)
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            cycle_count <= 32'd0;
        end else begin
            cycle_count <= cycle_count + 32'd1;
        end
    end

    // Tạo xung nhịp clk (chu kỳ 10ns)
    always #5 clk = ~clk;

    initial begin
        clk = 0;
        rst_n = 0;
        cycle_count = 0;
        
        // Nạp tệp firmware hex vào bộ nhớ ảo
        $readmemh("test.hex", memory_array);
        $display("[INFO] Da nap thanh cong tep test.hex vao bo nhớ ảo.");

        // Giữ tín hiệu reset trong 20ns
        #20; 
        rst_n = 1; 
        $display("[INFO] Thuc thi giai phong Reset, bat dau do dem chu ky...");

        // Chờ thời gian thực thi thuật toán Vigenère (điều chỉnh thời gian này tùy theo độ dài firmware)
        #1000000; 

        // Trích xuất kết quả tường minh ngay trên màn hình console
        $display("==================================================");
        $display("[RESULT] Tong so chu ky xung nhịp (Cycle Counts): %0d", cycle_count);
        $display("==================================================");
        
        $finish;
    end
endmodule

