namespace Problems.Test;


public static class TwoSumTestCaseSources
{
    public static IEnumerable<TestCaseData> TwoSum
    {
        get
        {
            yield return new TestCaseData(new[] { 2, 7, 11, 15 }, 9).Returns(new[] { 0, 1 });
            yield return new TestCaseData(new[] { 3, 2, 4 }, 6).Returns(new[] { 1, 2 });
            yield return new TestCaseData(new[] { 3, 3 }, 6).Returns(new[] { 0, 1 });
        }
    }
}

public class Tests
{
    [SetUp]
    public void Setup()
    {
    }

    [Test]
    [TestCaseSource(typeof(TwoSumTestCaseSources), nameof(TwoSumTestCaseSources.TwoSum))]
    public ICollection<int> TestTwoSum(ICollection<int> nums, int target)
    {
        return TwoSumSolution.TwoSum(nums, target);
    }
}