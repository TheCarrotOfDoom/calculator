
class Operation:
    def __init__(self,lhs,rhs):
        self.lhs = lhs
        self.rhs = rhs


class Add(Operation):
    def __init__(self, lhs, rhs):
        super().__init__(lhs, rhs)

    def evaluate(self):
        self.result = self.lhs + self.rhs

    def __str__(self) -> str:
        return self.lhs + " + " + self.rhs


class Subtract(Operation):
    def __init__(self, lhs, rhs):
        super().__init__(lhs, rhs)

    def evaluate(self):
        self.result = self.lhs - self.rhs

    def __str__(self) -> str:
        return self.lhs + " - " + self.rhs


class Multiply(Operation):
    def __init__(self, lhs, rhs):
        super().__init__(lhs, rhs)

    def evaluate(self):
        self.result = self.lhs - self.rhs

    def __str__(self) -> str:
        return self.lhs + " * " + self.rhs