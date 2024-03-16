/**
 * Retrieves the translation of text.
 *
 * @see https://developer.wordpress.org/block-editor/reference-guides/packages/packages-i18n/
 */
import { __ } from "@wordpress/i18n";

/**
 * React hook that is used to mark the block wrapper element.
 * It provides all the necessary props like the class name.
 *
 * @see https://developer.wordpress.org/block-editor/reference-guides/packages/packages-block-editor/#useblockprops
 */
import { InspectorControls, useBlockProps } from "@wordpress/block-editor";
import {
	PanelBody,
	TextControl,
	TextareaControl,
	ToggleControl,
	RangeControl,
} from "@wordpress/components";

/**
 * The edit function describes the structure of your block in the context of the
 * editor. This represents what the editor will render when the block is used.
 *
 * @see https://developer.wordpress.org/block-editor/reference-guides/block-api/block-edit-save/#edit
 *
 * @return {Element} Element to render.
 */
export default function Edit({ attributes, setAttributes }) {
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

	return (
		<>
			<InspectorControls>
				<PanelBody title={__("Settings", "scaling-feat-block")}>
					<TextControl
						label={__("Feat Title", "scaling-feat-block")}
						value={featTitle || ""}
						onChange={(value) => setAttributes({ featTitle: value })}
					/>
					<ToggleControl
						checked={!!showFlavorField}
						label={__("Feat has 'Flavor' field", "scaling-feat-block")}
						onChange={() =>
							setAttributes({
								showFlavorField: !showFlavorField,
							})
						}
					/>
					{showFlavorField && (
						<TextareaControl
							label={__("Feat Flavor", "scaling-feat-block")}
							value={featFlavor || ""}
							onChange={(value) => setAttributes({ featFlavor: value })}
						/>
					)}
					<TextControl
						label={__("Feat Prerequisites", "scaling-feat-block")}
						value={featPrerequisites || ""}
						onChange={(value) => setAttributes({ featPrerequisites: value })}
					/>
					<TextControl
						label={__("Feat Benefit", "scaling-feat-block")}
						value={featBenefit || ""}
						onChange={(value) => setAttributes({ featBenefit: value })}
					/>
					<RangeControl
						label="Number of Thresholds"
						value={featThresholdCount || 2}
						onChange={(value) => setAttributes({ featThresholdCount: value })}
						min={2}
						max={10}
					/>
					{featThresholdCount >= 0 && (
						<>
							{featThresholdCount >= 1 && (
								<>
									<TextControl
										label={__("Scale Threshold 1", "scaling-feat-block")}
										value={featScaleThreshold1 || ""}
										onChange={(value) => {
											setAttributes({ featScaleThreshold1: value });
										}}
									/>
									<TextareaControl
										label={__("Scale Benefit 1", "scaling-feat-block")}
										value={featScaleBenefit1 || ""}
										onChange={(value) => {
											setAttributes({ featScaleBenefit1: value });
										}}
									/>
								</>
							)}
							{featThresholdCount >= 2 && (
								<>
									<TextControl
										label={__("Scale Threshold 2", "scaling-feat-block")}
										value={featScaleThreshold2 || ""}
										onChange={(value) => {
											setAttributes({ featScaleThreshold2: value });
										}}
									/>
									<TextareaControl
										label={__("Scale Benefit 2", "scaling-feat-block")}
										value={featScaleBenefit2 || ""}
										onChange={(value) => {
											setAttributes({ featScaleBenefit2: value });
										}}
									/>
								</>
							)}
							{featThresholdCount >= 3 && (
								<>
									<TextControl
										label={__("Scale Threshold 3", "scaling-feat-block")}
										value={featScaleThreshold3 || ""}
										onChange={(value) => {
											setAttributes({ featScaleThreshold3: value });
										}}
									/>
									<TextareaControl
										label={__("Scale Benefit 3", "scaling-feat-block")}
										value={featScaleBenefit3 || ""}
										onChange={(value) => {
											setAttributes({ featScaleBenefit3: value });
										}}
									/>
								</>
							)}
							{featThresholdCount >= 4 && (
								<>
									<TextControl
										label={__("Scale Threshold 4", "scaling-feat-block")}
										value={featScaleThreshold4 || ""}
										onChange={(value) => {
											setAttributes({ featScaleThreshold4: value });
										}}
									/>
									<TextareaControl
										label={__("Scale Benefit 4", "scaling-feat-block")}
										value={featScaleBenefit4 || ""}
										onChange={(value) => {
											setAttributes({ featScaleBenefit4: value });
										}}
									/>
								</>
							)}
							{featThresholdCount >= 5 && (
								<>
									<TextControl
										label={__("Scale Threshold 5", "scaling-feat-block")}
										value={featScaleThreshold5 || ""}
										onChange={(value) => {
											setAttributes({ featScaleThreshold5: value });
										}}
									/>
									<TextareaControl
										label={__("Scale Benefit 5", "scaling-feat-block")}
										value={featScaleBenefit5 || ""}
										onChange={(value) => {
											setAttributes({ featScaleBenefit5: value });
										}}
									/>
								</>
							)}
							{featThresholdCount >= 6 && (
								<>
									<TextControl
										label={__("Scale Threshold 6", "scaling-feat-block")}
										value={featScaleThreshold6 || ""}
										onChange={(value) => {
											setAttributes({ featScaleThreshold6: value });
										}}
									/>
									<TextareaControl
										label={__("Scale Benefit 6", "scaling-feat-block")}
										value={featScaleBenefit6 || ""}
										onChange={(value) => {
											setAttributes({ featScaleBenefit6: value });
										}}
									/>
								</>
							)}
							{featThresholdCount >= 7 && (
								<>
									<TextControl
										label={__("Scale Threshold 7", "scaling-feat-block")}
										value={featScaleThreshold7 || ""}
										onChange={(value) => {
											setAttributes({ featScaleThreshold7: value });
										}}
									/>
									<TextareaControl
										label={__("Scale Benefit 7", "scaling-feat-block")}
										value={featScaleBenefit7 || ""}
										onChange={(value) => {
											setAttributes({ featScaleBenefit7: value });
										}}
									/>
								</>
							)}
							{featThresholdCount >= 8 && (
								<>
									<TextControl
										label={__("Scale Threshold 8", "scaling-feat-block")}
										value={featScaleThreshold8 || ""}
										onChange={(value) => {
											setAttributes({ featScaleThreshold8: value });
										}}
									/>
									<TextareaControl
										label={__("Scale Benefit 8", "scaling-feat-block")}
										value={featScaleBenefit8 || ""}
										onChange={(value) => {
											setAttributes({ featScaleBenefit8: value });
										}}
									/>
								</>
							)}
							{featThresholdCount >= 9 && (
								<>
									<TextControl
										label={__("Scale Threshold 9", "scaling-feat-block")}
										value={featScaleThreshold9 || ""}
										onChange={(value) => {
											setAttributes({ featScaleThreshold9: value });
										}}
									/>
									<TextareaControl
										label={__("Scale Benefit 9", "scaling-feat-block")}
										value={featScaleBenefit9 || ""}
										onChange={(value) => {
											setAttributes({ featScaleBenefit9: value });
										}}
									/>
								</>
							)}
							{featThresholdCount >= 10 && (
								<>
									<TextControl
										label={__("Scale Threshold 10", "scaling-feat-block")}
										value={featScaleThreshold10 || ""}
										onChange={(value) => {
											setAttributes({ featScaleThreshold10: value });
										}}
									/>
									<TextareaControl
										label={__("Scale Benefit 10", "scaling-feat-block")}
										value={featScaleBenefit10 || ""}
										onChange={(value) => {
											setAttributes({ featScaleBenefit10: value });
										}}
									/>
								</>
							)}
						</>
					)}
					<ToggleControl
						checked={!!showSpecialField}
						label={__("Feat has 'Special' field", "scaling-feat-block")}
						onChange={() =>
							setAttributes({
								showSpecialField: !showSpecialField,
							})
						}
					/>
					{showSpecialField && (
						<TextControl
							label={__("Feat Specials", "scaling-feat-block")}
							value={featSpecials || ""}
							onChange={(value) => setAttributes({ featSpecials: value })}
						/>
					)}
				</PanelBody>
			</InspectorControls>

			<div {...useBlockProps()}>
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
		</>
	);
}
