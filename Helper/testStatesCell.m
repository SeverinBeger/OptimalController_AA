function testStatesCell(StatesCell,v_no,h_no,phi_no)

testmatrix = zeros(v_no,h_no,phi_no);

for i=1:v_no
    for j=1:h_no
        for k=1:phi_no
            testmatrix(i,j,k) = ~isempty(StatesCell{i,j,k});
        end
    end
end

outputmat = sum(testmatrix,3)