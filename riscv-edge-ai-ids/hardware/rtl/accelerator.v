// ==========================================
// 4. TẦNG PHẦN CỨNG RTL (Verilog Metal Logic)
// ==========================================
module accelerator (
    input wire clk,
    input wire rst_n,
    input wire [31:0] data_in,
    output reg [31:0] data_out
);
    // Khối tính toán phần cứng thuần túy (Systolic/MAC logic)
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            data_out <= 32'b0;
        else
            data_out <= data_in + 32'd1; // Mạch xử lý đơn vị
    end
endmodule
