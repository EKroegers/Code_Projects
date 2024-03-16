/**
 * React hook that is used to mark the block wrapper element.
 * It provides all the necessary props like the class name.
 *
 * @see https://developer.wordpress.org/block-editor/reference-guides/packages/packages-block-editor/#useblockprops
 */
import { useBlockProps } from "@wordpress/block-editor";

/**
 * The save function defines the way in which the different attributes should
 * be combined into the final markup, which is then serialized by the block
 * editor into `post_content`.
 *
 * @see https://developer.wordpress.org/block-editor/reference-guides/block-api/block-edit-save/#save
 *
 * @param {Object} props            Properties passed to the function.
 * @param {Object} props.attributes Available block attributes.
 *
 * @return {Element} Element to render.
 */
export default function save({ attributes }) {
	const {
		featTitle,
		showFlavorField,
		featFlavor,
		featPrerequisites,
		featBenefit,
		featThresholdCount,
		featScaleThreshold1,
		featScaleBenefit1,
		featScaleThreshold2,
		featScaleBenefit2,
		featScaleThreshold3,
		featScaleBenefit3,
		featScaleThreshold4,
		featScaleBenefit4,
		featScaleThreshold5,
		featScaleBenefit5,
		featScaleThreshold6,
		featScaleBenefit6,
		featScaleThreshold7,
		featScaleBenefit7,
		featScaleThreshold8,
		featScaleBenefit8,
		featScaleThreshold9,
		featScaleBenefit9,
		featScaleThreshold10,
		featScaleBenefit10,
		showSpecialField,
		featSpecials,
	} = attributes;

	// If there is no content, which could happen if the block
	// is loaded from a template/pattern, return null. In this case, block
	// rendering will be handled by the render.php file.
	if (!featTitle) {
		return null;
	} else if (!showFlavorField) {
		return null;
	} else if (!featFlavor) {
		return null;
	} else if (!featPrerequisites) {
		return null;
	} else if (!featBenefit) {
		return null;
	} else if (!featThresholdCount) {
		return null;
	} else if (!featScaleThreshold1) {
		return null;
	} else if (!featScaleBenefit1) {
		return null;
	} else if (!featScaleThreshold2) {
		return null;
	} else if (!featScaleBenefit2) {
		return null;
	} else if (!featScaleThreshold3) {
		return null;
	} else if (!featScaleBenefit3) {
		return null;
	} else if (!featScaleThreshold4) {
		return null;
	} else if (!featScaleBenefit4) {
		return null;
	} else if (!featScaleThreshold5) {
		return null;
	} else if (!featScaleBenefit5) {
		return null;
	} else if (!featScaleThreshold6) {
		return null;
	} else if (!featScaleBenefit6) {
		return null;
	} else if (!featScaleThreshold7) {
		return null;
	} else if (!featScaleBenefit7) {
		return null;
	} else if (!featScaleThreshold8) {
		return null;
	} else if (!featScaleBenefit8) {
		return null;
	} else if (!featScaleThreshold9) {
		return null;
	} else if (!featScaleBenefit9) {
		return null;
	} else if (!featScaleThreshold10) {
		return null;
	} else if (!featScaleBenefit10) {
		return null;
	} else if (!showSpecialField) {
		return null;
	} else if (!featSpecials) {
		return null;
	}

	return (
		<div {...useBlockProps.save()}>
			<h4>{featTitle}</h4>
			{showFlavorField && (
				<p>
					<i>{featFlavor}</i>
				</p>
			)}
			<p>
				<strong>Prerequisite(s): </strong>
				{featPrerequisites}
			</p>
			<p>
				<strong>Benefit: </strong>
				{featBenefit}
			</p>
			{featThresholdCount >= 1 && (
				<p>
					<strong>{featScaleThreshold1}: </strong>
					{featScaleBenefit1}
				</p>
			)}
			{featThresholdCount >= 2 && (
				<p>
					<strong>{featScaleThreshold2}: </strong>
					{featScaleBenefit2}
				</p>
			)}
			{featThresholdCount >= 3 && (
				<p>
					<strong>{featScaleThreshold3}: </strong>
					{featScaleBenefit3}
				</p>
			)}
			{featThresholdCount >= 4 && (
				<p>
					<strong>{featScaleThreshold4}: </strong>
					{featScaleBenefit4}
				</p>
			)}
			{featThresholdCount >= 5 && (
				<p>
					<strong>{featScaleThreshold5}: </strong>
					{featScaleBenefit5}
				</p>
			)}
			{featThresholdCount >= 6 && (
				<p>
					<strong>{featScaleThreshold6}: </strong>
					{featScaleBenefit6}
				</p>
			)}
			{featThresholdCount >= 7 && (
				<p>
					<strong>{featScaleThreshold7}: </strong>
					{featScaleBenefit7}
				</p>
			)}
			{featThresholdCount >= 8 && (
				<p>
					<strong>{featScaleThreshold8}: </strong>
					{featScaleBenefit8}
				</p>
			)}
			{featThresholdCount >= 9 && (
				<p>
					<strong>{featScaleThreshold9}: </strong>
					{featScaleBenefit9}
				</p>
			)}
			{featThresholdCount >= 10 && (
				<p>
					<strong>{featScaleThreshold10}: </strong>
					{featScaleBenefit10}
				</p>
			)}
			{showSpecialField && (
				<p>
					<strong>Special: </strong>
					{featSpecials}
				</p>
			)}
		</div>
	);
}
