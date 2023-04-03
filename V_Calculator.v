// Code your design here
module V_Calculator();
  parameter n=32'd11;
  reg [24:0] instruction_set[0:n-1];
  reg [24:0] instn;
  reg[2:0] op; // 8 values 1-8
  reg[9:0] a, b;
  reg[9:0] res;
  integer fl=0;
  integer file_out;
  

  initial begin 
    $readmemb("intermediate.txt", instruction_set);
    file_out = $fopen("V_result.txt", "w");
 
    #5
    for (integer i=0; i<n; i = i + 1)
      begin
        instn=instruction_set[i];
        op = instn[24:22];
        a = instn[20:11];
        b = instn[9:0];
        fl = 0;
        if (instn[21]==1) begin 
          a=-a;        
        end
        if (instn[10]==1) begin 
          b=-b;        
        end
        
//         $display("%b",instn);
//         $display("%b %d %d",op,a,b);
        if(op == 3'b000)begin
          res <= a + b;
        end

        else if(op == 3'b001)begin
          res <= a - b;
        end

        else if(op == 3'b010)begin
          res <= a * b;
        end
        
        else if(op == 3'b011)begin
          res <= a / b;
        end

        else if(op == 3'b100)begin
          res <= a >> b;
        end

        else if(op == 3'b101)begin
          res <= a << b;
        end

        else if(op == 3'b110)begin
          res <= a & b;
        end

        else if(op == 3'b111)begin
          res <= a | b;
        end
        #5
        if (res[8]==1 || res[9]==1) begin
          res[9] = 1; 
          fl = 10;
        end

        #10
        if (fl==10) begin
          $fdisplay(file_out, "-%d",-res);
        end
        else begin
          $fdisplay(file_out, "%d",res);
        end
       
        
      end
    
      $fclose(file_out);
  end

  
endmodule